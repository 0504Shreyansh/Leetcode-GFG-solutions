#define mod 1000000007
class Solution {
public:
    int solve(int n, int prev, int times, vector<int>& rollMax, vector<vector<vector<int>>>& dp) {
        if(n == 0) {
            return 1;
        }
        if(dp[n][prev][times] != -1) {
            return dp[n][prev][times];
        }
        int curr = 0;
        for(int i = 0; i < 6; i++) {
            if(i + 1 != prev) {  // if different outcome, accept it and keep track
                curr = (curr + solve(n - 1, i + 1, 1, rollMax, dp)) % mod;
            }
            else {
                if(times != rollMax[i]) {  // make sure prev turns do not exceed repeat limit
                    curr = (curr + solve(n - 1, prev, times + 1, rollMax, dp)) % mod;
                }
            }
        }
        return dp[n][prev][times] = curr;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp(n + 1, 
                vector<vector<int>> (7, vector<int> (16, -1)));
        return solve(n, 0, 0, rollMax, dp);
    }
};