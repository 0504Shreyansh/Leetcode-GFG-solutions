class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> dp(m + 1, 0);
        
        for(int i = 1; i <= n; i++) {
            dp[0] = 1;
            for(int j = m; j >= 1; j--) {
                if(s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[m];
    }
};