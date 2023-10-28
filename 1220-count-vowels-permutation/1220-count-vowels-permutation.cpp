class Solution {
public:
    int countVowelPermutation(int n) {
        const int mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long> (6, 1));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][0] = dp[i + 1][1];
            dp[i][1] = (dp[i + 1][0] + dp[i + 1][2]) % mod;     
            dp[i][2] = (dp[i + 1][0] + dp[i + 1][1] + dp[i + 1][3] + dp[i + 1][4]) % mod;
            dp[i][3] = (dp[i + 1][2] + dp[i + 1][4]) % mod;
            dp[i][4] = dp[i + 1][0];
            dp[i][5] = (dp[i + 1][0] + dp[i + 1][1] + dp[i + 1][2] + dp[i + 1][3] + dp[i + 1][4]) % mod;
        }
        return dp[0][5];
    }
};