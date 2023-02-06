class Solution {
private:
    void dfs(vector<vector<int>>&grid, vector<vector<int>> &visited, int i, int j, int &currArea) {
        visited[i][j] = 1;
        currArea++;
        int n = grid.size(), m = grid[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int k=0;k<4;k++) {
            int new_x = i + dx[k], new_y = j + dy[k];
            if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && !visited[new_x][new_y] && grid[new_x][new_y])
                dfs(grid, visited, new_x, new_y, currArea);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size(), maxArea = 0;
        vector<vector<int>> visited(n,vector<int>(m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j]) {
                    int currArea = 0;
                    dfs(grid, visited, i, j, currArea);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        
        return maxArea;
    }
};