class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;
        for (int t = 0; t <= target; t++) {
            for (auto &it : nums) {
                if (t >= it) {
                    dp[t] += dp[t - it];
                }
            }
        }
        return dp[target];
    }
};