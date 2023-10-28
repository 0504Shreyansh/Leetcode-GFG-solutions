class Solution {
public:
    int countVowelPermutation(int n) {
        const int mod = 1e9 + 7;
        vector<long long> dp(6, 1), cur(6, 1);
        for (int i = n - 1; i >= 0; i--) {
            cur[0] = dp[1];
            cur[1] = (dp[0] + dp[2]) % mod;     
            cur[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % mod;
            cur[3] = (dp[2] + dp[4]) % mod;
            cur[4] = dp[0];
            cur[5] = (dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) % mod;
            dp = cur;
        }
        return dp[5];
    }
};