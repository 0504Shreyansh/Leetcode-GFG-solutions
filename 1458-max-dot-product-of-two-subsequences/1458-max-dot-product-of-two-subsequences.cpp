class Solution {
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int N = A.size();
        int M = B.size();
        vector<vector<vector<int>>> dp(N + 1, 
            vector<vector<int>> (M + 1, vector<int> (2, -1)));
        
        // Base cases
        for(int i = 0; i <= N; i++) {
            dp[i][M][0] = -1e9;
            dp[i][M][1] = 0;
        }
        for(int j = 0; j <= M; j++) {
            dp[N][j][0] = -1e9;
            dp[N][j][1] = 0;
        }
        
        for(int i = N - 1; i >= 0; i--) {
            for(int j = M - 1; j >= 0; j--) {
                for(int flag = 1; flag >= 0; flag--) {
                    int skip1 = dp[i + 1][j][flag];
                    int skip2 = dp[i][j + 1][flag];
                    int take = (A[i] * B[j]) + dp[i + 1][j + 1][1];
                    dp[i][j][flag] = max({skip1, skip2, take});
                }
            }
        }
        return dp[0][0][0];
    }
};