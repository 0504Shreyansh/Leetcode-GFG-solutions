class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int maxGap = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }
        return maxGap;
    }
};