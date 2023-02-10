class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int farthestDistance = -1;
        queue<pair<int,int>> q;
        int n = grid.size();
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col])
                    q.push({row, col});
            }
        }
        
        if(!q.size() || q.size()==n*n)
            return -1;
        
        vector<vector<int>> visited(n, vector<int> (n));
        int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
        
        while (q.size()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto curr = q.front();
                q.pop();
                int curr_row = curr.first, curr_col = curr.second;
                for (int index = 0; index < 4; index++) {
                    int new_row = curr_row + dx[index];
                    int new_col = curr_col + dy[index];
                    if(new_row>=0 && new_row<n && new_col>=0 && new_col<n && !visited[new_row][new_col] && !grid[new_row][new_col]) {
                        visited[new_row][new_col] = 1;
                        q.push({new_row, new_col});
                    }
                }            
            }
            farthestDistance++;
        }
        
        return farthestDistance;
    }
};