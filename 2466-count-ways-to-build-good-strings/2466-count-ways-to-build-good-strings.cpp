#define mod 1000000007
class Solution {
public:
    int solveIt(int len, int zero, int one, vector<int>& dp) {
        // Created a string
        if(len == 0) {
            return 1;
        }

        if(dp[len] != -1) {
            return dp[len];
        }

        // Count number of ways to build by 'zero' 0's
        int cur = 0;
        if(len >= zero) {
            cur = (cur + solveIt(len - zero, zero, one, dp)) % mod;
        }
        // Count number of ways to build by 'one' 1's 
        if(len >= one) {
            cur = (cur + solveIt(len - one, zero, one, dp)) % mod;
        }

        return dp[len] = cur;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        int ans = 0;
        for(int len = low; len <= high; len++) 
            ans = (ans + solveIt(len, zero, one, dp)) % mod;
        return ans;
    }
};