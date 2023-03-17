class Solution {
public:
    int solve(int i, int m, int n, vector<string>& strs, vector<vector<vector<int>>>& dp) {
        if (i<0) 
            return 0;
        if (dp[i][m][n] != -1) 
            return dp[i][m][n];
        int zeroes = count(strs[i].begin(),strs[i].end(),'0');
        int ones = strs[i].size() - zeroes;
        
        if (m >= zeroes && n >= ones)
            return dp[i][m][n] = max(solve(i-1, m, n, strs, dp), 1+solve(i-1, m-zeroes, n-ones, strs, dp));
        else
            return dp[i][m][n] = solve(i-1, m, n, strs, dp);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int size = strs.size();
        vector<vector<vector<int>>> dp(size+1, 
            vector<vector<int>> (m+1, vector<int> (n+1, -1)));
    
        return solve(size-1, m, n, strs, dp);    
    }
};