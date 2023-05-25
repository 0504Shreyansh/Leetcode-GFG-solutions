#define mod 1000000007
class Solution {
public:
    int distinctSequences(int n) {
        // 2 conditions
        // gcd of adjacent is 1
        // repetition at a gap of more than 1
        // prev2 -> prev ka prev, prev -> exact prev
        vector<vector<int>> dp(7, vector<int> (7, 0));
        vector<vector<int>> cur(7, vector<int> (7, 0));
        
        // Base case
        for(int prev = 0; prev <= 6; prev++) {
            for(int prev2 = 0; prev2 <= 6; prev2++) {
                dp[prev][prev2] = 1;
            }
        }
        
        for(int i = 1; i <= n; i++) {
            for(int prev = 0; prev <= 6; prev++) {
                for(int prev2 = 0; prev2 <= 6; prev2++) {
                    int curr = 0;
                    for(int roll = 1; roll <= 6; roll++) {
                        if(prev == 0) {  // first pick
                            curr = (curr + dp[roll][prev]) % mod;
                        }
                        else if(prev2 == 0) {  // second pick
                            if(prev != roll && __gcd(prev, roll) == 1) {
                                curr = (curr + dp[roll][prev]) % mod;
                            }
                        }
                        else if(prev2 != roll && prev != roll && __gcd(prev, roll) == 1) {
                            curr = (curr + dp[roll][prev]) % mod;
                        }
                    }
                    cur[prev][prev2] = curr;
                }
            }
            dp = cur;
        }
        
        return dp[0][0];
    }
};