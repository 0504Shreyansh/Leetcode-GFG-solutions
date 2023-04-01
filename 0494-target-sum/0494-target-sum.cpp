class Solution {
public:
    int solve(int i, vector<int>& nums, int target) {
        if(i==nums.size()) {
            return (target==0) ? 1 : 0;
        }
        int takePlus = solve(i+1, nums, target+nums[i]);
        int takeMinus = solve(i+1, nums, target-nums[i]);
        return takePlus + takeMinus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, nums, target);
    }
};