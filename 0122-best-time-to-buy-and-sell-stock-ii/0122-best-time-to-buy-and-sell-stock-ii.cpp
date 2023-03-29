class Solution {
public:
    /* METHOD 1 : RECURSION
    int recSol(int i, int N, int buy, vector<int>& prices) {
        if(i >= N) return 0;
        if(buy == 0) 
            return max(recSol(i+1, N, buy, prices), -prices[i] + recSol(i+1, N, 1, prices));
        return max(recSol(i+1, N, buy, prices), prices[i] + recSol(i+1, N, 0, prices));
    }*/
    
    /* METHOD 1 : MEMOIZATION 
    int memoizedSol(int i, int N, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(i >= N) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 0) 
            return dp[i][buy] = max(memoizedSol(i+1, N, buy, prices, dp), -prices[i] + memoizedSol(i+1, N, 1, prices, dp));
        return dp[i][buy] = max(memoizedSol(i+1, N, buy, prices, dp), prices[i] + memoizedSol(i+1, N, 0, prices, dp));
    }*/
    
    /* METHOD 3 : TABULATION
    int tabulatedSol(vector<int>& prices) {
        int N = prices.size();
        vector<vector<int>> dp(N+1, vector<int> (2, 0));
        for(int i = N-1; i >= 0; i--) { 
            dp[i][0] = max(dp[i+1][0], -prices[i]+dp[i+1][1]);        
            dp[i][1] = max(dp[i+1][1], +prices[i]+dp[i+1][0]);
        }
        return dp[0][0];
    }
    */
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<int> ahead(2, 0), cur(2, 0);
        ahead[0] = ahead[1] = 0;
        for(int i = N-1; i >= 0; i--) { 
            cur[0] = max(ahead[0], -prices[i]+ahead[1]);        
            cur[1] = max(ahead[1], +prices[i]+ahead[0]);
            ahead = cur;
        }
        return cur[0];
    }
};