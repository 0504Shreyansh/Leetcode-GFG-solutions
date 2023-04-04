class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        vector<vector<int>> dp(N, vector<int> (M, 0));
        int maxSize = 0;

        for(int i = 0; i < N; i++) {
            if(matrix[i][0]=='1') {
                dp[i][0] = 1;
                maxSize = 1;
            }
        }

        for(int j = 0; j < M; j++) {
            if(matrix[0][j]=='1') {
                dp[0][j] = 1;
                maxSize = 1;
            }
        }

        for(int i = 1; i < N; i++) {
            for(int j = 1; j < M; j++) {
                if(matrix[i][j]=='1') {
                    int  up = dp[i-1][j];
                    int left = dp[i][j-1];
                    int diagonal = dp[i-1][j-1];
                    dp[i][j] = 1 + min({up, left, diagonal});
                    maxSize = max(maxSize, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        
        int maxArea = maxSize * maxSize;
        return maxArea;
    }
};