class Solution {
public:
    /* METHOD 1 : RECURSION
    int recSol(int i, int N, int buy, vector<int>& prices) {
        if(i >= N) return 0;
        if(buy==0) 
            return max(recSol(i+1, N, buy, prices), -prices[i] + recSol(i+1, N, 1, prices));
        return max(recSol(i+1, N, buy, prices), +prices[i] + recSol(i+2, N, 0, prices));  // Cooldown day, so skip 1 day
    }*/
    
    /* METHOD 2 : MEMOIZATION
    int memoizedSol(int i, int N, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(i >= N) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy==0) 
            return dp[i][buy] = max(memoizedSol(i+1, N, buy, prices, dp), -prices[i] + memoizedSol(i+1, N, 1, prices, dp));
        return dp[i][buy] = max(memoizedSol(i+1, N, buy, prices, dp), +prices[i] + memoizedSol(i+2, N, 0, prices, dp));  // Cooldown day, so skip 1 day
    }*/
    
    /* METHOD 3 : TABULATION
    int tabulatedSol(vector<int>& prices) {
        int N = prices.size();
        vector<vector<int>> dp(N+2, vector<int> (2, 0));
        for(int i = N-1; i >= 0; i--) {
            dp[i][0] = max(dp[i+1][0], -prices[i]+dp[i+1][1]);
            dp[i][1] = max(dp[i+1][0], +prices[i]+dp[i+2][0]);            
        }
        return dp[0][0];
    }*/
    
    int maxProfit(vector<int>& prices) {
        // METHOD 4 : SPACE OPTIMISATION
        int N = prices.size();
        vector<int> cur(2, 0), next(2, 0), nextNext(2, 0);
        for(int i = N-1; i >= 0; i--) {
            cur[0] = max(next[0], -prices[i]+next[1]);
            cur[1] = max(next[1], +prices[i]+nextNext[0]);
            nextNext = next;
            next = cur;
        }
        return cur[0];   
    }
};