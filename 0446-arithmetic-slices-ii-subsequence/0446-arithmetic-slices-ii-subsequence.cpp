class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        map<int, unordered_map<long long, int>> dp;
        int n = nums.size(), ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = 1LL * nums[i] - 1LL * nums[j];
                dp[i][d] += dp[j][d] + 1;
                ans += dp[j][d];
            }
        }
        return ans;
    }
};