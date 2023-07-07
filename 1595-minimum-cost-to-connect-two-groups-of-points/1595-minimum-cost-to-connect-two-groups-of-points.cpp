class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        vector<vector<vector<int>>> dp(n + 1, 
            vector<vector<int>> (m + 1, 
                vector<int> ((1 << m), 1e5)));  // --> dp[0][0][0]
        
        for(int j = 0; j < m; j++) {
            dp[n][j][(1<<m)-1] = 0;
        }
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                for(int mm = 0; mm < (1<<m); mm++) {
                    int takeAndStayInRow = 1e5, skipValueAndStayInRow = 1e5;
                    if(j + 1 != m) 
                        skipValueAndStayInRow = dp[i][j + 1][mm];

                    if(j + 1 != m) 
                        takeAndStayInRow = cost[i][j] + dp[i][j + 1][mm | (1 << j)];

                    int takeAndSkipRow = cost[i][j] + dp[i + 1][0][mm | (1 << j)];
                    dp[i][j][mm] = min({skipValueAndStayInRow, 
                                                 takeAndSkipRow, takeAndStayInRow});
                }
            }
        }
        
        return dp[0][0][0];
    }
};