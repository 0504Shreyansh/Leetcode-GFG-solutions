#define mod 1000000007
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (5, -1));
        for(int i = 0; i < 5; i++) {
            dp[1][i] = 1;
        }
        for(int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i - 1][1]) % mod;  //a
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;  //e
            dp[i][2] = ((((dp[i - 1][0] + dp[i - 1][1]) % mod) + dp[i - 1][3]) % mod + dp[i - 1][4]) % mod;   //i
            dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % mod;  //o
            dp[i][4] = (dp[i - 1][0]) % mod;  //u
        }
        int ans = 0;
        // count all vowels
        for(int i = 0; i < 5; i++) 
            ans = (ans + dp[n][i]) % mod;
        return ans;
    }
};