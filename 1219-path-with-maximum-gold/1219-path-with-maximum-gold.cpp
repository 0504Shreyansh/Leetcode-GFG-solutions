class Solution {
public:
    int ans = 0;
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int sum) {
        vis[i][j] = 1;
        sum += grid[i][j];
        ans = max(ans, sum);
        for(auto x : dir) {
            int newX = i + x.first, newY = j + x.second;
            if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && !vis[newX][newY] && grid[newX][newY]) 
                dfs(newX, newY, grid, vis, sum);
        }
        vis[i][j] = 0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    vector<vector<int>> vis(n, vector<int> (m));
                    dfs(i, j, grid, vis, 0);
                } 
            } 
        }
        return ans;
    }
};