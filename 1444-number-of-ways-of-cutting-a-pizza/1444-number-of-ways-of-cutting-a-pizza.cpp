class Solution
{
public:
    int dfs(int m, int n, int k, int r, int c, vector<vector<vector<int>>> &dp, vector<vector<int>> &preSum)
    {
        if (preSum[r][c] == 0) return 0;
        if (k == 0)   return 1;
        if (dp[k][r][c] != -1) return dp[k][r][c];
        int ans = 0;
        //horizontal cuts (row - wise)
        for (int nr = r + 1; nr < m; nr++){
        //  here we are checking that the upper part have any apples or not and also the lower part have apples or not ---- if preSum[r][c] - preSum[nr][c] is minus means the lower part do not have apples or if preSum[r][c] - preSum[nr][c] ==0 means the upper part do not have apples 
        //the same logic is in the new coulmn for loop
         if (preSum[r][c] - preSum[nr][c] > 0){
          ans = (ans + dfs(m, n, k - 1, nr, c, dp, preSum)) % 1000000007;
            }     
        }
        //verticle cuts (colum-wise)
        for (int nc = c + 1; nc < n; nc++){
         if (preSum[r][c] - preSum[r][nc] > 0){
          ans = (ans + dfs(m, n, k - 1, r, nc, dp, preSum)) % 1000000007; 
            }       
        }    
        return dp[k][r][c] = ans;
    }
    int ways(vector<string> &pizza, int k)
    {
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> dp(vector(k, vector(m, vector(n, -1))));
        vector<vector<int>> preSum(vector(m + 1, vector(n + 1, 0)));
        //making prefix sum means (r, c)represents how many apples are present from(r , c) to (m , n)
        //this is also a dp hehehehe dp inside dp (very good ji)
        //we are starting from the bottom and computing
        for (int r = m - 1; r >= 0; r--){
             for (int c = n - 1; c >= 0; c--){
                 preSum[r][c] = preSum[r][c + 1] + preSum[r + 1][c] - preSum[r + 1][c + 1] + (pizza[r][c] == 'A');
             }
                
        }   
        return dfs(m, n, k - 1, 0, 0, dp, preSum);
    }
    
};