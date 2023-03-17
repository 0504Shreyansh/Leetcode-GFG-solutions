class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    queue<pair<int,int>> Q;
    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 2;
        for(auto [x, y] : dir) {
            int X = i + x, Y = j + y;
            if(X>=0 && X<grid.size() && Y>=0 && Y<grid[0].size() && grid[X][Y]==1)
                dfs(X, Y, grid);
        }              
        Q.push({i, j});
    } 
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    found = true; break;
                }
            }
            if(found) break;
        }
        
        int steps = 0;
        
        while (Q.size()) {
            int size = Q.size();
            while (size--) {
                auto cur = Q.front();
                Q.pop();
                int i = cur.first, j = cur.second;
                for (auto [x, y] : dir) {
                    int X = i + x, Y = j + y;
                    if (X>=0 && X<n && Y>=0 && Y<m) {
                        if (grid[X][Y] == 1)
                            return steps;
                        if (grid[X][Y] == 0) {
                            Q.push({X, Y});
                            grid[X][Y] = 2;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};