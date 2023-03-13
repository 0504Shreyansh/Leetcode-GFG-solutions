class Solution {
public:
    int ans = 0;
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int i, int j, vector<vector<int>>& grid, int sum) {
        int prev = grid[i][j], n = grid.size(), m = grid[0].size();
        sum += prev;
        grid[i][j] = -1;
        ans = max(ans, sum);
        for(auto [x, y] : dir) {
            int newX = i + x, newY = j + y;
            if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]!=-1 && grid[newX][newY]) 
                dfs(newX, newY, grid, sum);
        }
        grid[i][j] = prev;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                dfs(i, j, grid, 0); 
            
        return ans;
    }
};