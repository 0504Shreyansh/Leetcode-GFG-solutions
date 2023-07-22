class Solution {
private:
    vector<pair<int, int>> dir = {{-2, -1}, {-2, 1}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {1, 2}, {1, -2}};
    double count(int n, int k, int i, int j, vector<vector<vector<double>>>& dp) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        if (k == 0) {
            return 1.0;
        }
        double curr = 0;
        for (auto [x, y] : dir) 
            curr += count(n, k - 1, i + x, j + y, dp);
        return dp[i][j][k] = curr / 8; 
    }

public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,
         vector<vector<double>> (n, vector<double> (k+1, -1)));
        return count(n, k, row, column, dp);
    }
};