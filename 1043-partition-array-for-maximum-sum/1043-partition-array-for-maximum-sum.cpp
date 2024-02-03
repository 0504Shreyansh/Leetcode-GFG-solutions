class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {	
            int maxx = 0;
            for (int j = i; j < min(i + k, n); ++j) {
                maxx = max(maxx, arr[j]);
                dp[i] = max(dp[i], maxx * (j - i + 1) + dp[j + 1]);
            }
        }
        return dp[0];
    }
};