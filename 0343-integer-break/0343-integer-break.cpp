class Solution {
private:
    int dp[60][60];
    int solve(int n, int k) {
        if (n == 0) return (k >= 2) ? 1 : 0;
        if (dp[n][k] != -1) return dp[n][k];
        int ans = 1;
        for (int i = 1; i <= n; i++)
            ans = max(ans, i * solve(n - i, k + 1));
        return dp[n][k] = ans;
    }
public:
    int integerBreak(int n) {
        memset(dp, -1, sizeof dp);
        return solve(n, 0);
    }
};