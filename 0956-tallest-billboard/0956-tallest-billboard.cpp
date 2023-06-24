class Solution {
public:
    int solve(int index, int sum, vector<int>& rods, vector<vector<int>>& dp) {
        if(index >= rods.size()) {
            return (sum == 0) ? sum : INT_MIN;
        }
        if(dp[index][sum + 5000] != -1) {
            return dp[index][sum + 5000];
        }
        int pick1 = rods[index] + solve(index + 1, sum + rods[index], rods, dp);
        int pick2 = solve(index + 1, sum - rods[index], rods, dp);
        int notPick = solve(index + 1, sum, rods, dp);
        return dp[index][sum + 5000] = max({pick1, pick2, notPick});
    }
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>> dp(rods.size(), vector<int> (10002, -1));
        return solve(0, 0, rods, dp);
    }
};