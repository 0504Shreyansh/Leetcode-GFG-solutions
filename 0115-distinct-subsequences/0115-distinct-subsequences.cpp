class Solution {
public:
    unsigned long long solve(int i, int j, string &s, string &t, vector<vector<unsigned long long>>& dp) {
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1]) return dp[i][j] = (solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp));
        return dp[i][j] = solve(i - 1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> prev(m + 1, 0);
        vector<unsigned long long> dp(m + 1, 0);
        
        // Base case
        for(int j = 0; j <= m; j++)
            prev[j] = 0;
        prev[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            dp[0] = 1;
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[j] = prev[j - 1] + prev[j];
                }
                else {
                    dp[j] = prev[j];
                }
            }
            prev = dp;
        }
        return dp[m];
    }
};