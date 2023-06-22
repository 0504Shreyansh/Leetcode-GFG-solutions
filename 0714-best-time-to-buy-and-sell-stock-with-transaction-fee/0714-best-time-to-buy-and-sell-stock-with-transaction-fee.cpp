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
        vector<int> dp(2, 0), prev(2, 0);
        // return solve(0, prices, 0, fee, dp);
        
        for(int i = n - 1; i >= 0; i--) {
            dp[0] = max(prev[0], -prices[i] + prev[1]);
            dp[1] = max(prev[1], prices[i] - fee + prev[0]);
            prev = dp;
        }
        return dp[0];
    }
};