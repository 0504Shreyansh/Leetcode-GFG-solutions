class Solution {
public:
    int solve(int i, int n, int pasteLength, vector<vector<int>>& dp) {
        if(i==n)   // Is possible to print n chars
            return 0;
        if(i > n)  // Prints more chars, don't consider
            return 1e8;
        if(dp[i][pasteLength] != -1) // Already pre-computed
            return dp[i][pasteLength];
        // 1 op. req. and length inc. by pasteLength
        int onlyPaste = 1 + solve(i+pasteLength, n, pasteLength, dp);
        // 2 bcoz of copy and paste op., newLength is 2*original and new paste length becomes equal to the previous length that was present
        int copyAndPaste = 2 + solve(2*i, n, i, dp);
        return dp[i][pasteLength] = min(copyAndPaste, onlyPaste);
    }
    int minSteps(int n) {
        // Edge case -> no operation required
        if(n==1) 
            return 0;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // 1 + bcoz we are taking in account the first copy operation
        return 1 + solve(1, n, 1, dp); 
    }
};