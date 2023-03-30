class Solution {
public:
    /* METHOD 1 : RECURSION 
    int recSol(int i, int N, int k, int buy, vector<int>& prices) {
        if(i >= N || k == 0) return 0;
        if(buy == 0)
            return max(recSol(i+1, N, k, buy, prices), -prices[i]+recSol(i+1, N, k, 1, prices));
        return max(recSol(i+1, N, k, buy, prices), +prices[i]+recSol(i+1, N, k-1, 0, prices));
    }*/
    
    /* METHOD 2 : MEMOIZATION
    int memoizedSol(int i, int N, int k, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(i >= N || k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        if(buy == 0)
            return dp[i][buy][k] = max(memoizedSol(i+1, N, k, buy, prices, dp), -prices[i]+memoizedSol(i+1, N, k, 1, prices, dp));
        return dp[i][buy][k] = max(memoizedSol(i+1, N, k, buy, prices, dp), +prices[i]+memoizedSol(i+1, N, k-1, 0, prices, dp));
    }*/
    
    int maxProfit(int k, vector<int>& prices) {
        // Tabulation
        int N = prices.size();
        // 3-D DP
        vector<vector<vector<int>>> dp(N+1, 
                                vector<vector<int>> (2, vector<int> (k+1, -1)));
        
        // Base case 1 : i==N 
        for(int buy = 0; buy <= 1; buy++) {
            for(int kk = 0; kk <= k; kk++) {
                dp[N][buy][kk] = 0;
            }
        }
        
        // Base case 2 : k==0 
        for(int i = 0; i <= N; i++) {
            for(int buy = 0; buy <= 1; buy++) {
                dp[i][buy][0] = 0;
            }
        }
        
        for(int i = N-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int limit = 1; limit <= k; limit++) {
                    if(buy == 0)
                        dp[i][buy][limit] = max(dp[i+1][buy][limit], -prices[i]+dp[i+1][1][limit]);
                    else 
                        dp[i][buy][limit] = max(dp[i+1][buy][limit], +prices[i]+dp[i+1][0][limit-1]);
                }
            }
        }
        
        return dp[0][0][k];
    }
};