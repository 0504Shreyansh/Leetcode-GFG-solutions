class Solution {
public:
    const int mod = 1e9 + 7;
    int solve(int curPos, int steps, int arrLen, vector<vector<int>>& dp) {
        
        if(curPos < 0 || curPos >= arrLen) {
            return 0;
        }
        
        if(steps == 0) {
            return (curPos == 0) ? 1 : 0;
        }
        
        if(dp[curPos][steps] != -1) {
            return dp[curPos][steps];
        }
        
        int goBackWays = solve(curPos - 1, steps - 1, arrLen, dp);
        int goForwardWays = solve(curPos + 1, steps - 1, arrLen, dp);
        int stay = solve(curPos, steps - 1, arrLen, dp);
        return dp[curPos][steps] = ((goBackWays + goForwardWays) % mod + stay) % mod;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int> (steps + 1, -1));
        return solve(0, steps, arrLen, dp);
    }
};