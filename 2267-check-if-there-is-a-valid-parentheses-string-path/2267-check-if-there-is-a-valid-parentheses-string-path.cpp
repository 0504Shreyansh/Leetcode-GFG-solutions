class Solution {
public:
    int solve(int i, int j, int ob_cb, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size(), m = grid[i].size();
        ob_cb += (grid[i][j] == '(') ? 1 : -1;
        if(ob_cb < 0) return 0;
        if(i == n - 1 && j == m - 1) {
            return (ob_cb == 0);
        }
        if(dp[i][j][ob_cb] != -1) {
            return dp[i][j][ob_cb];
        }
        int paths = 0;
        if(i + 1 < n && solve(i + 1, j, ob_cb, grid, dp)) return dp[i][j][ob_cb] = true;
        if(j + 1 < m && solve(i, j + 1, ob_cb, grid, dp)) return dp[i][j][ob_cb] = true;
        return dp[i][j][ob_cb] = false;
    }

    // Leetcode 2267. Check if there is a Valid Parantheses String Path
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0] == ')') return false;
        int n = grid.size(), m = grid[0].size();
        if((m+n-1)&1) return false;
        vector<vector<vector<int>>> dp(n, 
            vector<vector<int>> (m, vector<int> (n+m+1, -1)));
        return solve(0, 0, 0, grid, dp);
    }
};