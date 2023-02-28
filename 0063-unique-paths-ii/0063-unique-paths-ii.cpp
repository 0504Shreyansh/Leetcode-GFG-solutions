class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m));
        
        // Check if it is not blocked
        if(obstacleGrid[0][0]==0)
            dp[0][0] = 1;
        // [0,0,1,0,0]=>[1,1,0,0,0](Further 0 after 1 is not reachable)
        for(int i = 1; i < n; i++) 
            if(obstacleGrid[i][0]==0)
                dp[i][0] = dp[i-1][0];

        for(int j = 1; j < m; j++) 
            if(obstacleGrid[0][j]==0)
                dp[0][j] = dp[0][j-1];
        
        // (i, j) can be reached by (i-1, j) and (i, j-1)
        // if it is not an obstacle!
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[i][j]==0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[n-1][m-1];
    }
};