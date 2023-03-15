class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        //Sorting bcoz it is optimal to change either the first or the last vals,
        //So, to obtain the minimum of difference between the largest and smallest
        sort(nums.begin(), nums.end());
        int n = nums.size();
        //Change the first teo eles
        int firstOp = nums[n-1] - nums[2];
        //Change the furst and the last eles
        int secondOp = nums[n-2] - nums[1];
        //Change the the last two eles
        int thirdOp = nums[n-3] - nums[0];
        
        return min(firstOp, min(secondOp, thirdOp));
        
    }
};