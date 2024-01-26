class Solution {
private:
    int dirs[5] = {0, -1, 0, 1, 0};
    const int mod = 1e9 + 7;
    int solve(int row, int col, int moves, int m, int n, vector<vector<vector<int>>>& dp) {
        if (row < 0 || row >= m || col < 0 || col >= n) return 1;
        if (moves == 0) return 0;
        int& ans = dp[row][col][moves], res = 0;
        if (ans != -1) return ans;
        for (int k = 0; k < 4; k++) {
            res = (res + solve(row + dirs[k], col + dirs[k + 1], moves - 1, m, n, dp)) % mod;
        }
        return ans = res;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove + 1, -1)));
        return solve(startRow, startColumn, maxMove, m, n, dp);
    }
};