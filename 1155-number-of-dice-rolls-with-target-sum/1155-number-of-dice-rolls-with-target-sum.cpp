#define mod 1000000007
class Solution {
public:
    int dp[31][1001];
    int solve(int n, int k, int target) {
        if(n==0) {
            return (target==0) ? 1 : 0;
        }

        if(dp[n][target] != -1) 
            return dp[n][target];

        int ans = 0;
        for(int i = 1; i <= k; i++) {
            if(target >= i) {
                ans = (ans + solve(n-1, k, target-i)) % mod;
            }
        }

        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, 0));
    
        // return solve(n, k, target);
        
       
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int t = 1; t <= target; t++) {
                for(int x = 1; x <= k && t - x >= 0; x++) {
                    dp[i][t] += dp[i - 1][t - x];
                    dp[i][t] = dp[i][t] % mod;
                }
            }
        }
        return dp[n][target];   
    }
};