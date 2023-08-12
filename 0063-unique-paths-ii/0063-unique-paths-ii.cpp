class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>> dp(N, vector<int> (M, 0));
        // Base case
        for (int j = 0; j < M; j++) {
            if (grid[0][j] == 1) break;
            dp[0][j] = 1;
        }
        for (int i = 0; i < N; i++) {
            if (grid[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (grid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        } 
        return dp[N - 1][M - 1];
    }
};