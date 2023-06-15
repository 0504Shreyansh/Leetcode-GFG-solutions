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
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long> (m + 1, -1));
        return solve(n, m, s, t, dp);
    }
};