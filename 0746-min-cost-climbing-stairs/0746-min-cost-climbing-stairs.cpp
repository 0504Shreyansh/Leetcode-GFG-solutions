class Solution {
private:
    int f(int i, vector<int>& cost, vector<int>& dp) {
        if (i >= cost.size()) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(f(i + 1, cost, dp), f(i + 2, cost, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(f(0, cost, dp), f(1, cost, dp));
    }
};