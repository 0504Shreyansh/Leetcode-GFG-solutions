class Solution {
public:
    /* METHOD 1 : RECURSION
    int solve(int i, int j, vector<vector<int>>& matrix) {
        if(i == matrix.size()-1)
            return matrix[i][j];
        int down = solve(i+1, j, matrix);
        int leftDiagonal = 1e9, rightDiagonal = 1e9;
        if(j > 0) leftDiagonal = solve(i+1, j-1, matrix);
        if(j < matrix.size()-1) rightDiagonal = solve(i+1, j+1, matrix);
        return dp[i][j] = matrix[i][j] + min({down, leftDiagonal, rightDiagonal});
    }*/
    /* METHOD 2 : MEMOIZATION
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(i == matrix.size()-1)
            return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = solve(i+1, j, matrix, dp);
        int leftDiagonal = 1e9, rightDiagonal = 1e9;
        if(j > 0) leftDiagonal = solve(i+1, j-1, matrix, dp);
        if(j < matrix.size()-1) rightDiagonal = solve(i+1, j+1, matrix, dp);
        return dp[i][j] = matrix[i][j] + min({down, leftDiagonal, rightDiagonal});
    }*/
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Space optimisation
        int N = matrix.size();
        vector<int> prev(matrix[0]), cur(N);
        for(int i = 1; i < N; i++) {
            for(int j = 0; j < N; j++) {
                int down = prev[j];
                int leftDiagonal = 1e9, rightDiagonal = 1e9;
                if(j > 0) leftDiagonal = prev[j-1];
                if(j < N-1) rightDiagonal = prev[j+1];
                cur[j] = matrix[i][j] + min({down, leftDiagonal, rightDiagonal});
            }
            prev = cur;
        }

        return *min_element(begin(prev),end(prev));   
    }
};