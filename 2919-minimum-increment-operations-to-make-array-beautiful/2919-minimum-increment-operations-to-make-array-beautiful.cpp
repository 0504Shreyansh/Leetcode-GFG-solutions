class Solution {
private:
    long long solve(int i, int n, int k, vector<int>& nums, vector<long long>& dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        long long ans = 2e16;
        for (int j = i; j < min(n, i + 3); j++) {
            ans = min(ans, (max(0, k - nums[i])) + min({solve(i + 1, n, k, nums, dp), solve(i + 2, n, k, nums, dp), solve(i + 3, n, k, nums, dp)}));
        }
        return dp[i] = ans;
    }
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n, -1);
        long long ans = 2e16;
        for (int i = 0; i < 3; i++) {
            ans = min(ans, solve(i, n, k, nums, dp));
        }
        return ans;
    }
};