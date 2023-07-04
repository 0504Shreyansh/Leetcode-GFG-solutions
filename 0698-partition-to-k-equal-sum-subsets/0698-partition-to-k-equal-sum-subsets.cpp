class Solution {
public:
    bool solve(int i, int mask, int k, int currSum, int reqSum, vector<int>& nums, vector<int>& dp) {
        if(mask == (1 << nums.size()) - 1) return true;
        if(currSum == reqSum) {
            return solve(0, mask, k - 1, 0, reqSum, nums, dp);
        }
        if(i >= nums.size()) {
            return false;
        }
        if(dp[mask] != -1) return dp[mask];
        bool ans = false;
        for(int j = i; j < nums.size(); j++) {
            if(mask & (1 << j)) continue;
            if(nums[j] + currSum <= reqSum) {
                if(solve(j + 1, mask | (1 << j), k, currSum + nums[j], reqSum, nums, dp)) {
                    return dp[mask] = true;
                }
            }
        }
        return dp[mask] = false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            totSum += nums[i];
        if(totSum % k != 0) {
            return false;
        }
        vector<int> dp((1 << nums.size()), -1);
        return solve(0, 0, k, 0, totSum / k, nums, dp);
    }
};