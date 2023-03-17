class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int res = nums[0];
        vector<int> dpMin(nums), dpMax(nums);
        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] < 0)
            {
                dpMin[i] = min(nums[i], nums[i] * dpMax[i-1]);
                dpMax[i] = max(nums[i], nums[i] * dpMin[i-1]);
            }
            else
            {
                dpMin[i] = min(nums[i], nums[i] * dpMin[i-1]);
                dpMax[i] = max(nums[i], nums[i] * dpMax[i-1]);
            }
            res = max(res, dpMax[i]);
        }
        
        return res;
    }
};