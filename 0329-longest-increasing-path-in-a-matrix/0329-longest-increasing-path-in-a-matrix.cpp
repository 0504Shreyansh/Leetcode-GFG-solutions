class Solution {
private:
    int dirs[5] = {0, -1, 0, 1, 0};
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
            int X = i + dirs[k], Y = j + dirs[k + 1];
            if (0 <= X && X < grid.size() && 0 <= Y && Y < grid[0].size() && grid[i][j] < grid[X][Y]) {
                cnt = max(cnt, 1 + dfs(X, Y, grid, dp));
            }
        }
        return dp[i][j] = cnt;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, 1 + dfs(i, j, grid, dp));
            }
        }
        return res;
    }
};