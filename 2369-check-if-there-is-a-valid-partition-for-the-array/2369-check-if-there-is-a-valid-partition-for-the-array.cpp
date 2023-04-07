class Solution {
public:
    int dp[100001];
    bool solve(vector<int> &nums, int i=0) {
        int n = nums.size();
        if(i>=n) {
            return true;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        bool res = false;
        // case 1
        if((i+1) < n) {
            if(nums[i] == nums[i+1]) res = res|solve(nums, i+2);
        }

        // case 2
        if((i+2) < n) {
            if(nums[i] == nums[i+1] && nums[i+1] == nums[i+2])
                res = res | solve(nums, i+3);
        }

        // case 3
        if((i+2) < n) {
            if((nums[i+1]-nums[i]) == 1 && (nums[i+2]-nums[i+1]) == 1)
                res = res | solve(nums, i+3);
        }

        return dp[i] = res;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return solve(nums);
    }
};