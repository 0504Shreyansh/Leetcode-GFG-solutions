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
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0, prices, 0, fee, dp);
    }
};