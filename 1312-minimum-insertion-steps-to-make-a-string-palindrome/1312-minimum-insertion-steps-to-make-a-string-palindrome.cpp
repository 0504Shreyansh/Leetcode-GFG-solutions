class Solution {
public:
    int minInsertions(string s) {
        
        string r(s);
        reverse(begin(r),end(r));
        
        int N = s.size();
        vector<vector<int>> dp(N+1, vector<int> (N+1, 0));
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (s[i-1]==r[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // Palindrome is found as an lcs of the a string and its reverse
        int lcs = dp[N][N];
        
        // So, insert N-length(lcs) chars that are required
        return N - lcs;
    }
};