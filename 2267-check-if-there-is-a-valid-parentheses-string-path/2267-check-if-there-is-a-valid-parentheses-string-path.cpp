class Solution {
public:
    int solve(int i, int j, int ob_cb, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp) {
        if(i >= grid.size() || j >= grid[0].size()) {
            return false;
        }
        if(grid[i][j] == ')' && ob_cb == 0) {
            return false;
        }
        if(dp[i][j][ob_cb] != -1) {
            return dp[i][j][ob_cb];
        }
        if(i == grid.size() - 1 && j == grid[0].size() - 1) {
            return ob_cb + ((grid[i][j] == '(') ? 1 : -1) == 0;
        }
        return dp[i][j][ob_cb] = solve(i + 1, j, ob_cb + ((grid[i][j] == '(') ? 1 : -1), grid, dp) |
                                solve(i, j + 1, ob_cb + ((grid[i][j] == '(') ? 1 : -1), grid, dp);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, 
            vector<vector<int>> (m + 1, vector<int> (n + m + 1, -1)));
        return solve(0, 0, 0, grid, dp);
    }
};