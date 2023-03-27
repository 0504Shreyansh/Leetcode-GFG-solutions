class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int N = word1.size();
        int M = word2.size();
        
        vector<vector<int>> dp(N+1, vector<int> (M+1));
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // Delete the characters excluding the LCS to minimise the # of operations
        return (N + M - 2*dp[N][M]);
    }
};