class Solution {
private:
    const int mod = 1e9 + 7;
    int count(int steps, int pos, int arrLen, vector<vector<int>>& dp) {
        if (pos < 0 || pos >= arrLen) return 0;
        if (steps == 0) return (pos == 0) ? 1 : 0;
        if (dp[steps][pos] != -1) return dp[steps][pos];
        return dp[steps][pos] = ((count(steps - 1, pos, arrLen, dp) + count(steps - 1, pos - 1, arrLen, dp)) % mod + count(steps - 1, pos + 1, arrLen, dp)) % mod;
    }
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int> (min(arrLen, steps + 1), -1));
        return count(steps, 0, arrLen, dp);
    }
};