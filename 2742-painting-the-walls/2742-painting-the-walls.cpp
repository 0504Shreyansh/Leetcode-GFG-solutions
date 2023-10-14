class Solution {
private:
    int solve(int i, int c, int n, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
        if (i >= n) return (c >= 0) ? 0 : 1e9;
        if (dp[i][c + n] != -1) return dp[i][c + n];
        int ans = solve(i + 1, c - 1, n, cost, time, dp);
        ans = min(ans, cost[i] + solve(i + 1, c + time[i], n, cost, time, dp));
        return dp[i][c + n] = ans;
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        int sum = accumulate(begin(time), end(time), 0);
        vector<vector<int>> dp(n, vector<int> (sum + n, -1));
        return solve(0, 0, n, cost, time, dp);
    }
};