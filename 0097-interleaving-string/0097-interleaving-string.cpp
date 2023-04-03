class Solution {
public:
    bool solve(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>>& dp) {
        
        if(k==0) 
            return true;
        
        if(i-1>=0 || j-1>=0) {
            if(i-1>=0 && j-1>=0) {
                if(dp[i][j] != -1) return dp[i][j];
            } 
            if(i-1>=0 && j-1>=0 && k-1>=0 && s1[i-1]==s3[k-1] && s2[j-1]==s3[k-1])
                return dp[i][j] = solve(i-1, j, k-1, s1, s2, s3, dp) || 
                    solve(i, j-1, k-1, s1, s2, s3, dp);
            if(i-1>=0 && k-1>=0 && s1[i-1]==s3[k-1])
                return dp[i][j] = solve(i-1, j, k-1, s1, s2, s3, dp);
            if(j-1>=0 && k-1>=0 && s2[j-1]==s3[k-1])
                return dp[i][j] = solve(i, j-1, k-1, s1, s2, s3, dp);
        }
        
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
       
        int N = s1.size(), M = s2.size(), S = s3.size();
        if(N + M != S)
            return false;
        vector<vector<int>> dp(N+1, vector<int> (M+1, -1));
        return solve(N, M, S, s1, s2, s3, dp);
        
    }
};