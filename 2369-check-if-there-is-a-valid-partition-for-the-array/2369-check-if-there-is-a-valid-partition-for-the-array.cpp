class Solution {
public:
    bool validPartition(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, false);
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n && A[i] == A[i + 1]) 
                dp[i] |= dp[i + 2];
            if (i + 2 < n && A[i] == A[i + 1] && A[i] == A[i + 2]) 
                dp[i] |= dp[i + 3];
            if (i + 2 < n && A[i + 1] - A[i] == 1 && A[i + 2] - A[i + 1] == 1)
                dp[i] |= dp[i + 3];
        }
        return dp[0];
    }
};