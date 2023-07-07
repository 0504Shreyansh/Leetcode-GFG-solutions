class Solution {
private:
    int solve(int i, int j, int mask, vector<vector<int>>& cost,
              vector<vector<vector<int>>>& dp) {
        if(i >= cost.size()) {
            if(mask == (1 << cost[0].size()) - 1) {
                return 0;
            }
            return 1e5;
        }
        if(dp[i][j][mask] != -1) {
            return dp[i][j][mask];
        }
        int takeAndStayInRow = 1e5, skipValueAndStayInRow = 1e5;
        if(j + 1 != cost[i].size()) 
            skipValueAndStayInRow = solve(i, j + 1, mask, cost, dp);

        if(j + 1 != cost[i].size()) 
            takeAndStayInRow = cost[i][j] + solve(i, j + 1, mask | (1 << j), cost, dp);

        int takeAndSkipRow = cost[i][j] + solve(i + 1, 0, mask | (1 << j), cost, dp);
        return dp[i][j][mask] = min({skipValueAndStayInRow, 
                                     takeAndSkipRow, takeAndStayInRow});
    }

public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        vector<vector<vector<int>>> dp(n + 1, 
            vector<vector<int>> (m + 1, 
                vector<int> ((1 << m), 1e5)));
        // return solve(0, 0, 0, cost, dp);
        
        for(int j = 0; j < m; j++) {
            dp[n][j][(1<<m)-1] = 0;
        }
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                for(int mm = 0; mm < (1<<m); mm++) {
                    int takeAndStayInRow = 1e5, skipValueAndStayInRow = 1e5;
                    if(j + 1 != cost[i].size()) 
                        skipValueAndStayInRow = dp[i][j + 1][mm];

                    if(j + 1 != cost[i].size()) 
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