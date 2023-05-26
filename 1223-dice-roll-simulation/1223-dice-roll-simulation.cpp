#define mod 1000000007
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
     
        vector<vector<int>> dp(7, vector<int> (17, -1));
        vector<vector<int>> next(7, vector<int> (17, -1));
        
        for(int prev = 0; prev <= 6; prev++) {
            for(int times = 0; times <= 15; times++) {
                dp[prev][times] = 1;
            }
        }
        
        
        for(int i = 1; i <= n; i++) {
            for(int prev = 0; prev <= 6; prev++) {
                for(int times = 15; times >= 0; times--) {
                    int curr = 0;
                    for(int roll = 1; roll <= 6; roll++) {
                        if(roll != prev) { 
                            curr = (curr + dp[roll][1]) % mod;
                        }
                        else {
                            if(times != rollMax[roll - 1]) { 
                                curr = (curr + dp[prev][times + 1]) % mod;
                            }
                        }
                    }
                    next[prev][times] = curr;
                }
            }
            dp = next;
        }
        
        return dp[0][0];
    }
};