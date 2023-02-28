class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<long>> dp(m+1, vector<long> (n+1, 1));
        
        // Starting from cell (1, 1) bcoz possibility of reaching to row or col 1 is 1.
        // Kind of base case
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                // At cell (i, j) => it can have possibility from the upper or the left cell, so add their possiblities
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};