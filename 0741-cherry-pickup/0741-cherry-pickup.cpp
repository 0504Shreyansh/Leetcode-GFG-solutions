class Solution {
public:
    int dp[51][51][51][51];
    int solve(int r1, int c1, int r2, int c2, vector<vector<int>>& grid)
    {
        int n = grid.size();
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
        
        if((r1==n-1 && c1==n-1) || (r2==n-1 && c2==n-1)) 
            return grid[n-1][n-1];
        
        if(dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];
        
        int cur = 0;
        if(r1==r2 && c1==c2)
            cur = grid[r1][c1];   
        else
            cur = grid[r1][c1]+grid[r2][c2];
           
        cur += max({solve(r1+1, c1, r2+1, c2, grid), 
                     solve(r1, c1+1, r2, c2+1, grid),
                     solve(r1+1, c1, r2, c2+1, grid),
                     solve(r1, c1+1, r2+1, c2, grid)});
       
        return dp[r1][c1][r2][c2] = cur;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return max(0,solve(0,0,0,0,grid));
    }
};