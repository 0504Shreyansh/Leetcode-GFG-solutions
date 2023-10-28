class Solution {
public:
    const int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (26, -1));
        // dp[0][25]

        for (int i = 0; i < 26; i++) {
            dp[n][i] = 1;
        }
        for (int i = n -  1; i >= 0; i--) {
            for (char prev = 'z'; prev >= 'a'; prev--) {
                if (prev == 'z') {
                    dp[i][prev - 'a'] = ((((dp[i + 1][0] + dp[i + 1][4]) % mod + dp[i + 1][8]) % mod + dp[i + 1][14]) % mod + dp[i + 1][20]) % mod;
                }
                else if (prev == 'a') {
                    dp[i][prev - 'a'] = dp[i + 1][4];
                }
                else if (prev == 'e') {
                    dp[i][prev - 'a'] = (dp[i + 1][0] + dp[i + 1][8]) % mod;
                }
                else if (prev == 'i') {
                    dp[i][prev - 'a'] = (((dp[i + 1][0] + dp[i + 1][4]) % mod + dp[i + 1][14]) % mod + dp[i + 1][20]) % mod;
                }
                else if (prev == 'o') {
                    dp[i][prev - 'a'] = (dp[i + 1][8] + dp[i + 1][20]) % mod;
                } 
                else if (prev == 'u') {
                    dp[i][prev - 'a'] = dp[i + 1][0];
                }
            }
        }
        return dp[0][25];
    }
};