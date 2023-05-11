class Solution {
public:
    // Same as LCS !!!
    // Recursion
    int solve1(int i, int j, vector<int>& A, vector<int>& B) {
        if (i < 0 || j < 0) return 0;
        return (A[i] == B[j]) ? (1+solve1(i-1, j-1, A, B)) :
            max(solve1(i-1, j, A, B), solve1(i, j-1, A, B));
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int N = A.size();
        int M = B.size();
        vector<vector<int>> dp(N+1, vector<int> (M+1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                dp[i][j] = (A[i-1]==B[j-1]) ? 
                    (1 + dp[i-1][j-1]) : (max(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[N][M];
    }
};