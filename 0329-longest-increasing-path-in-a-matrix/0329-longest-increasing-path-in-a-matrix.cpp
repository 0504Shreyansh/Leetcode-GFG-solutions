class Solution {
public:
    vector<pair<int,int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        vis[i][j] = 1;
        int cur = 1;
        for(auto [dx, dy] : direction) {
            int newX = i + dx;
            int newY = j + dy;
            if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && !vis[newX][newY] && grid[i][j] < grid[newX][newY]) {
                cur = max(cur, 1 + dfs(newX, newY, grid, vis, dp));
            }
        }
        vis[i][j] = 0;
        return dp[i][j] = cur;
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        // dp[i][j] -> max. increasing path length which starts from cell (i, j)
        vector<vector<int>> dp(N + 1, vector<int> (M + 1, -1));
        vector<vector<int>> vis(N, vector<int> (M));
        int ans = 1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                ans = max(ans, dfs(i, j, grid, vis, dp));
            }
        }
        return ans;
    }
};