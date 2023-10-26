class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(begin(A), end(A));
        int n = A.size();
        vector<long> dp(n, 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] % A[j] == 0) {
                    int idx = lower_bound(begin(A), begin(A) + i, A[i] / A[j]) - begin(A);
                    if (idx >= 0 && idx < n && A[idx] == (A[i] / A[j])) {
                        dp[i] = (dp[i] + dp[j] * dp[idx]) % 1000000007;
                    }
                }
            }
            ans = (ans + dp[i]) % 1000000007;
        }
        return ans;
    }
};