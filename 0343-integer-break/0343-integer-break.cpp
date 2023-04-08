class Solution {
public:
    int dp[60][60];
    int solve(int n, int k) {
        if(k==0) {
            return n;
        }
        if(dp[n][k] != -1) {
            return dp[n][k];
        }
        int cur = 1;
        for(int num = 1; num < n; num++) {
            cur = max(cur, num*solve(n-num, k-1));
        }
        return dp[n][k] = cur;
    }

    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = 1;
        // Try out all possible partitions.
        for(int k = 1; k < n; k++) {
            ans = max(ans, solve(n, k));
        }
        return ans;
    }
};