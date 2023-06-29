struct State {
    int key;
    int row;
    int col;
    State(int _key, int _row, int _col) {
        key = _key;
        row = _row;
        col = _col;
    }
};
class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int start_row, start_col;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '@') {
                    start_row = i;
                    start_col = j;
                } else if(islower(grid[i][j])) {
                    cnt++;
                }
            }
        }
        int level = 0;
        int reqKeys = (1 << cnt) - 1;
        queue<State*> q;
        q.push(new State(0, start_row, start_col));
        vector<vector<vector<int>>> vis(n, 
                vector<vector<int>> (m, vector<int> (reqKeys + 1)));
        vis[start_row][start_col][0] = 1;

        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                State *curr = q.front();
                q.pop();
                int key = curr->key;
                int row = curr->row;
                int col = curr->col;
                if(key == reqKeys) {
                    return level;
                }
                for(auto v : dir) {
                    int new_row = row + v.first;
                    int new_col = col + v.second;
                    int prevKey = key;
                    if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                        char c = grid[new_row][new_col];
                        if(c == '#') {  // wall
                            continue;
                        }
                        if(islower(c)) {  // key found
                            prevKey |= (1 << (c - 'a'));
                        }
                        if(isupper(c) && ((prevKey >> (c - 'A')) & 1) == 0) {
                            continue;    // lock found while key not found
                        }
                        if(!vis[new_row][new_col][prevKey]) {
                            vis[new_row][new_col][prevKey] = 1;
                            q.push(new State(prevKey, new_row, new_col));  // not visited cell
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};