class Solution {
public:
    const int mod = 1e9 + 7;
    vector<pair<int,int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        for(auto [x, y] : direction) {
            int X = i + x;
            int Y = j + y;
            if(X >= 0 && X < grid.size() && Y >= 0 && Y < grid[0].size() && grid[i][j] < grid[X][Y]) {
                ans = (ans + 1 + dfs(X, Y, grid, dp)) % mod;
            }
        }
        return dp[i][j] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = (ans + 1 + dfs(i, j, grid, dp)) % mod;
            }
        }
        return ans;
    }
};