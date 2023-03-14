class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
            return nums[0];
        int maxSumPrev2 = nums[0];
        int maxSumPrev = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++)
        {
            int curSum = max(maxSumPrev2+nums[i], maxSumPrev);
            maxSumPrev2 = maxSumPrev;
            maxSumPrev = curSum;
        }
        
        return maxSumPrev;
        
    }
};