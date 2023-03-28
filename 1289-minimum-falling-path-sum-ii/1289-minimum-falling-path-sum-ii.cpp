class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i == n) 
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int take = 1e9;
        for(int k = 0; k < n; k++) {
            //Skip that is previously taken 
            if(k==j) continue;
            // Find out the minimum of all the possiblities
            take = min(take, grid[i][k] + solve(i+1, k, n, grid, dp));
        }
        return dp[i][j] = take;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        if(n==1)
            return grid[0][0];
        int res = 1e5;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        for(int j = 0; j < n; j++) {
            int x = solve(0, j, n, grid, dp);
            res = min(res, x);
        }        
        return res;
    }
};