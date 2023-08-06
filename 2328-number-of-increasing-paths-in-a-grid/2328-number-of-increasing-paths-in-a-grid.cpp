class Solution {
private:
    int dirs[5] = {0, -1, 0, 1, 0};
    const int mod = 1e9 + 7;
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] > grid[i][j]) {
                ans += 1 + dfs(x, y, grid, dp);
                ans %= mod;
            }
        }
        return dp[i][j] = ans;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += 1 + dfs(i, j, grid, dp);
                ans %= mod;
            }
        }
        return ans;
    }
};