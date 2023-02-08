class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int row, int col, int &numberOfEnclaves, bool toCount) {
        visited[row][col] = 1;
        if(toCount)
            numberOfEnclaves++;
        int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
        int n = grid.size(), m = grid[0].size();
        
        for (int index = 0; index < 4; index++) {
            int new_row = row + dx[index], new_col = col + dy[index];
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && !visited[new_row][new_col] && grid[new_row][new_col])
                dfs(grid, visited, new_row, new_col, numberOfEnclaves, toCount);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m));
        int numberOfEnclaves = 0;
        
        //Visit all the boundary 1's
        for (int row = 0; row < n; row++) {
            if (!visited[row][0] && grid[row][0])
                dfs(grid, visited, row, 0, numberOfEnclaves, 0);
            if (!visited[row][m-1] && grid[row][m-1])
                dfs(grid, visited, row, m-1, numberOfEnclaves, 0);
        }
        
        for (int col = 0; col < m; col++) {
            if (!visited[0][col] && grid[0][col])
                dfs(grid, visited, 0, col, numberOfEnclaves, 0);
            if (!visited[n-1][col] && grid[n-1][col])
                dfs(grid, visited, n-1, col, numberOfEnclaves, 0);
        }
        
//         //Then, count the number of enclaved 1's
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!visited[row][col] && grid[row][col])
                    dfs(grid, visited, row, col, numberOfEnclaves, 1);
            }
        }
        
        return numberOfEnclaves;
    }
};