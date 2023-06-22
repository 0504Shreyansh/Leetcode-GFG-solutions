class Solution {
public:
    int solve(int index, vector<int>& prices, int buy, int fee, vector<vector<int>>& dp) {
        if(index >= prices.size()) {
            return 0;
        }
        if(dp[index][buy] != -1) {
            return dp[index][buy];
        }
        if(buy == 0) {
            int skip = solve(index + 1, prices, buy, fee, dp);
            int buyHere = -prices[index] + solve(index + 1, prices, 1, fee, dp);
            return dp[index][buy] = max(skip, buyHere);
        }
        int skip = solve(index + 1, prices, buy, fee, dp);
        int sellHere = prices[index] - fee + solve(index + 1, prices, 0, fee, dp);
        return dp[index][buy] = max(skip, sellHere);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        // return solve(0, prices, 0, fee, dp);
        
        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = max(dp[i + 1][0], -prices[i] + dp[i + 1][1]);
            dp[i][1] = max(dp[i + 1][1], prices[i] - fee + dp[i + 1][0]);
        }
        return dp[0][0];
    }
};