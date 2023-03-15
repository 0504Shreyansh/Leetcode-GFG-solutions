class Solution {
public:
    bool isPossible(vector<int>& nums, int target) {
        
        // 2D -> 1D
        // TC -> O(n * sum/2)
        // SC -> O(sum/2)
        int n = nums.size();
        vector<bool> dp(target+1, false);
        
        // Base cases : 
        // target = 0 is always possible to make
        dp[0] = true;
        // if target = nums[0], then it is also possible to make
        if(nums[0] <= target) 
        {
            dp[nums[0]] = true;
        }
        
        for(int i = 1; i < n; i++) 
        {
            vector<bool> prev(target+1, false);
            prev[0] = true;
            for(int j = 1; j <= target; j++)
            {
                bool notTake = dp[j];
                bool take = false;
                // if it is valid to take (sum >= 0)
                if(nums[i] <= j) 
                {
                    take = dp[j-nums[i]];
                }
                // Check by both path take and notTake
                prev[j] = take | notTake;
            }
            dp = prev;
        }
        
        return dp[target];
        
    }
    bool canPartition(vector<int>& nums) {
        
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        
        if(totalSum & 1)
            return false;
          
        return isPossible(nums, totalSum/2);
        
    }
};