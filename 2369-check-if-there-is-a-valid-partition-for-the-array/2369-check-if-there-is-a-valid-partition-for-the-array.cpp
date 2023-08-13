class Solution {
private:
    bool solve(int i, vector<int>& A, int &n, vector<int>& dp) {
        if (i >= n) return true;
        if (dp[i] != -1) return dp[i];
        dp[i] = false;
        if (i + 1 < n && A[i] == A[i + 1]) dp[i] |= solve(i + 2, A, n, dp);
        if (i + 2 < n && A[i] == A[i + 1] && A[i] == A[i + 2]) dp[i] |= solve(i + 3, A, n, dp);
        if (i + 2 < n && A[i + 1] - A[i] == 1 && A[i + 2] - A[i + 1] == 1) dp[i] |= solve(i + 3, A, n, dp);
        return dp[i];
    }
public:
    bool validPartition(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, -1);
        return solve(0, A, n, dp);
    }
};