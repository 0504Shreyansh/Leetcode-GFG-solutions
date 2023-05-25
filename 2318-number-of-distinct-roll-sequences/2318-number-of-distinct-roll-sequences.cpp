#define mod 1000000007
class Solution {
public:
    int solve(int n, int prev, int prev2, vector<vector<vector<int>>>& dp) {
        if(n == 0) {
            return 1;
        }
        
        if(dp[n][prev][prev2] != -1) {
            return dp[n][prev][prev2];
        }
        
        int curr = 0;
        for(int roll = 1; roll <= 6; roll++) {
            if(prev == 0) {  // first pick
                curr = (curr + solve(n - 1, roll, prev, dp)) % mod;
            }
            else if(prev2 == 0) {  // second pick
                if(prev != roll && __gcd(prev, roll) == 1) {
                    curr = (curr + solve(n - 1, roll, prev, dp)) % mod;
                }
            }
            else if(prev2 != roll && prev != roll && __gcd(prev, roll) == 1) {
                curr = (curr + solve(n - 1, roll, prev, dp)) % mod;
            }
        }
        
        return dp[n][prev][prev2] = curr;
    }
    int distinctSequences(int n) {
        // 2 conditions
        // gcd of adjacent is 1
        // repetition at a gap of more than 1
        vector<vector<vector<int>>> dp(n + 1, 
                vector<vector<int>> (7, vector<int> (7, 0)));
        // prev2 -> prev ka prev, prev -> exact prev
        
        
        // Base case
        for(int prev = 0; prev <= 6; prev++) {
            for(int prev2 = 0; prev2 <= 6; prev2++) {
                dp[0][prev][prev2] = 1;
            }
        }
        
        for(int i = 1; i <= n; i++) {
            for(int prev = 0; prev <= 6; prev++) {
                for(int prev2 = 0; prev2 <= 6; prev2++) {
                    int curr = 0;
                    for(int roll = 1; roll <= 6; roll++) {
                        if(prev == 0) {  // first pick
                            curr = (curr + dp[i - 1][roll][prev]) % mod;
                        }
                        else if(prev2 == 0) {  // second pick
                            if(prev != roll && __gcd(prev, roll) == 1) {
                                curr = (curr + dp[i - 1][roll][prev]) % mod;
                            }
                        }
                        else if(prev2 != roll && prev != roll && __gcd(prev, roll) == 1) {
                            curr = (curr + dp[i - 1][roll][prev]) % mod;
                        }
                    }
                    dp[i][prev][prev2] = curr;
                }
            }
        }
        
        
        return dp[n][0][0];
    }
};