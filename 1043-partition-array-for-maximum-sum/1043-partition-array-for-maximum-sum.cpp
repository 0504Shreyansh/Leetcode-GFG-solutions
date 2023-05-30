class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        int N = A.size();
        vector<int> dp(N + 1, -1);
        dp[N] = 0;
        for(int i = N - 1; i >= 0; i--) {
            int currMax = A[i];
            for(int j = i; j < min(i + k, N); j++) {
                currMax = max(currMax, A[j]);
                dp[i] = max(dp[i], (j - i + 1) * currMax + dp[j + 1]);
            }
        }
        return dp[0];
    }
};