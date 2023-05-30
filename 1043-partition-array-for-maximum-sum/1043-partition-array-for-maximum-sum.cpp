class Solution {
public:
    int solve(int i, int k, vector<int>& A, vector<int>& dp) {
        int N = A.size();
        if(i >= N) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans = 0;
        int currMax = A[i];
        for(int j = i; j < min(N, i + k); j++) {
            currMax = max(currMax, A[j]);
            ans = max(ans, (j - i + 1) * currMax + solve(j + 1, k, A, dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        vector<int> dp(A.size(), -1);
        return solve(0, k, A, dp);
    }
};