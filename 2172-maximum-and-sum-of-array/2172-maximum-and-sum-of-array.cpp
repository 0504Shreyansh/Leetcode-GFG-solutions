class Solution {
private:
    int solve(int i, int mask1, int mask2, int numSlots, vector<int>& nums, vector<vector<int>>& dp) {
        if(i >= nums.size()) {
            return 0;
        }
        if(dp[mask1][mask2] != -1) {
            return dp[mask1][mask2];
        }
        int ans = INT_MIN;
        for(int m = 0; m < numSlots; m++) {
            if((mask1 & (1 << m)) == 0) {
                int curr = (nums[i] & (m + 1)) + 
                    solve(i + 1, mask1 | (1 << m), mask2, numSlots, nums, dp);
                ans = max(ans, curr);
            } else if((mask2 & (1 << m)) == 0) {
                int curr = (nums[i] & (m + 1)) + 
                    solve(i + 1, mask1, mask2 | (1 << m), numSlots, nums, dp);
                ans = max(ans, curr);
            }
        }
        return dp[mask1][mask2] = ans;
    }

public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<vector<int>> dp(1 << numSlots, vector<int> (1 << numSlots, -1));
        return solve(0, 0, 0, numSlots, nums, dp);
    }
};