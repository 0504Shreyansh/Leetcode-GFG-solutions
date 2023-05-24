class Solution {
public:
    int solve(int i, int j, bool flag, vector<int>& A, vector<int>& B, vector<vector<vector<int>>>& dp) {
        if(i >= A.size() || j >= B.size()) {
            return flag ? 0 : -1e9;
        }
        if(dp[i][j][flag] != -1) {
            return dp[i][j][flag];
        }
        int skip1 = solve(i + 1, j, flag, A, B, dp);
        int skip2 = solve(i, j + 1, flag, A, B, dp);
        int take = (A[i] * B[j]) + solve(i + 1, j + 1, true, A, B, dp);
        return dp[i][j][flag] = max({skip1, skip2, take});
    }
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int N = A.size();
        int M = B.size();
        vector<vector<vector<int>>> dp(N + 1, 
            vector<vector<int>> (M + 1, vector<int> (2, -1)));
        
        return solve(0, 0, false, A, B, dp);
    }
};