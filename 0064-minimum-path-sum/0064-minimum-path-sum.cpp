class Solution {
public:
    /*METHOD 1 : RECURISION
    int recSol(int n, int m, int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=n || j>=m) return 1e9;
        if(i==0 && j==0) return grid[0][0];
        return grid[i][j] + min(recSol(n,m,i-1,j,grid), recSol(n,m,i,j-1,grid));
    }*/
    /*  METHOD 2 : MEMOIZATION
    int memoizedSol(int n, int m, int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i<0 || j<0 || i>=n || j>=m) return 1e9;
        if(i==0 && j==0) return grid[0][0];
        if(dp[i][j] != -1) return dp[i][j]l
        return dp[i][j] = grid[i][j] + min(memoizedSol(n,m,i-1,j,grid,dp), memoizedSol(n,m,i,j-1,grid,dp));
    }*/
    /* METHOD 3 : TABULATION
    int tabulatedSol(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid);
        for(int i = 1; i < n; i++)
            dp[i][0] += dp[i-1][0];
        for(int j = 1; j < m; j++)
            dp[0][j] += dp[0][j-1];
        for(int i = 1; i < n; i++) 
            for(int j = 1; j < m; j++) 
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);        
        return dp[n-1][m-1];
    }
    */
    int minPathSum(vector<vector<int>>& grid) {
        // Space optimised
        int n = grid.size(), m = grid[0].size();
        vector<int> cur(m+1, 0), prev(grid[0]);
        for(int j = 1; j < m; j++)
            prev[j] += prev[j-1];
        
        for(int i = 1; i < n; i++) {
            cur[0] = grid[i][0] + prev[0];
            for(int j = 1; j < m; j++) {
                cur[j] = grid[i][j] + min(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return prev[m-1];
    }
};