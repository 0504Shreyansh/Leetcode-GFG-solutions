class Solution {
public:
    /* METHOD 1 : RECURSION
    int recSol(int i, int N, int buy, int limit, vector<int>& prices) {
        if(i == N || limit == 0) return 0;
        if(buy==0) 
            return max(recSol(i+1, N, buy, limit, prices), -prices[i] + recSol(i+1, N, 1, limit, prices));
        return max(recSol(i+1, N, buy, limit, prices), +prices[i] + recSol(i+1, N, 0, limit-1, prices));  
    }*/
    
    /* METHOD 2 : MEMOIZATION (3-D DP)
    int memoizedSol(int i, int N, int buy, int limit, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(i == N || limit == 0) return 0;
        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];
        if(buy==0) 
            return dp[i][buy][limit] = max(memoizedSol(i+1, N, buy, limit, prices, dp), -prices[i] + memoizedSol(i+1, N, 1, limit, prices, dp));
        return dp[i][buy][limit] = max(memoizedSol(i+1, N, buy, limit, prices, dp), +prices[i] + memoizedSol(i+1, N, 0, limit-1, prices, dp));  
    }*/
    
    /* METHOD 3 : TABULATION
    int tabulatedSol(vector<int>& prices) {
        // Tabulation 
        int N = prices.size();
        // 3-D DP
        vector<vector<vector<int>>> dp(N+1,
                        vector<vector<int>> (2, vector<int> (3, -1)));
        // Base case 1 : i==N
        for(int buy = 0; buy <= 1; buy++) {
            for(int limit = 0; limit <= 2; limit++) {
                dp[N][buy][limit] = 0;
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
                for(int limit = 0; limit <= 2; limit++) {
                    if(buy==0) {
                        dp[i][buy][limit] = max(dp[i+1][buy][limit], -prices[i]+dp[i+1][1][limit]);
                    }
                    else {
                        if(limit > 0)
                            dp[i][buy][limit] = max(dp[i+1][buy][limit], +prices[i]+dp[i+1][0][limit-1]);
                        else 
                            dp[i][buy][limit] = (dp[i+1][buy][limit]);
                    }
                }
            }
        }
        return dp[0][0][2];
    }*/
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        // Space Optimisation
        vector<vector<int>> cur(2, vector<int> (3, 0));
        vector<vector<int>> next(2, vector<int> (3, 0));
        
        for(int i = N-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                cur[buy][0] = (next[buy][0]);
                for(int limit = 1; limit <= 2; limit++) {
                    if(buy==0) 
                        cur[buy][limit] = max(next[buy][limit], -prices[i]+next[1][limit]);
                    else
                        cur[buy][limit] = max(next[buy][limit], +prices[i]+next[0][limit-1]);
                }
                next = cur;
            }
        }
        return cur[0][2];
    }
};
 
