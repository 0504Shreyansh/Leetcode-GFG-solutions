class Solution {
public:
    bool isInterleave(string A, string B, string C) {
        int n = A.size(), m = B.size(), k = C.size();
        if (n + m != k) return false;
        if (A == "") return (B == C);
        if (B == "") return (A == C);
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        for (int j = 0; j <= m; j++) {
            dp[0][j] = (B.substr(0, j) == C.substr(0, j));
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = (A.substr(0, i) == C.substr(0, i));
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                bool ans = false;
                if (A[i - 1] == C[i + j - 1]) {
                    ans |= dp[i - 1][j];
                }
                if (B[j - 1] == C[i + j - 1]) {
                    ans |= dp[i][j - 1];
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][m];
    }
};