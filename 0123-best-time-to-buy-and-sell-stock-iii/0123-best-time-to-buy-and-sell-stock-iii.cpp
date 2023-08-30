class Solution {
private:
    int solve(int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (i >= prices.size() || cap == 2) {
            return 0;
        }
        if (dp[i][buy][cap] != -1) {
            return dp[i][buy][cap];
        }
        if (buy == 0) {
            return dp[i][buy][cap] = max(solve(i + 1, 0, cap, prices, dp), -prices[i] + solve(i + 1, 1, cap, prices, dp));
        }
        return dp[i][buy][cap] = max(solve(i + 1, 1, cap, prices, dp), prices[i] + solve(i + 1, 0, cap + 1, prices, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (2, -1)));
        return solve(0, 0, 0, prices, dp);
    }
};