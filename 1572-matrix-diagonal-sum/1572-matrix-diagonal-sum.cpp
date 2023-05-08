class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int N = size(mat);
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += mat[i][i] + mat[i][N-i-1];
        }
        sum -= (N & 1) ? mat[N/2][N/2] : 0;
        return sum;
    }
};