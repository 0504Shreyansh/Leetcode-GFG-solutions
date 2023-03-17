class Solution {
public:
    /*Method 1 : Recursion
    int recSol(int i, int j, vector<vector<int>> &triangle) {
        if(i==triangle.size()-1) return triangle[i][j];
        return triangle[i][j] + min(recSol(i+1, j, triangle), recSol(i+1, j+1, triangle));
    }*/
    
    /*Method 2 : Memoization
    int memoizedSol(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
        if(i==triangle.size()-1) return dp[i][j] = triangle[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];
        return dp[i][j] = triangle[i][j] + min(memoizedSol(i+1, j, triangle, dp), memoizedSol(i+1, j+1, triangle, dp));
    }*/
    
    /*Method 3 : Tabulation
    int tabulatedSol(int n, vector<vector<int>>& triangle) {
        vector<vector<int>> dp(n, vector<int> (n, 1e9));
        for(int j = 0; j < n; j++)  //Base Case
            dp[n-1][j] = triangle[n-1][j];
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) { //Go down or diagonal
                int down = dp[i+1][j], diagonal = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(down, diagonal);
            }
        }
        return dp[0][0];
    }*/
    int minimumTotal(vector<vector<int>>& triangle) {
        // Space Optimisation
        // TC->O(N*N), SC->O(N) 
        int n = triangle.size();
        vector<int> dp(n, -1), prev(n, -1);
        for(int j = 0; j < n; j++)
            dp[j] = triangle[n-1][j];

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                int down = dp[j], diagonal = dp[j+1];
                prev[j] = triangle[i][j] + min(down, diagonal);
            }
            dp = prev;
        }

        return dp[0];
        
    }
};