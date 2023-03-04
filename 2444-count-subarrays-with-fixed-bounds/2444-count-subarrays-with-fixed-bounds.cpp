class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0; 
        int j = -1; 
        int prevMin = -1, prevMax = -1; 

        for(int i = 0; i < nums.size(); i++) { 
            if(nums[i] < minK || nums[i] > maxK)
                j = i; 
            if(nums[i] == minK)
                prevMin = i; 
            if(nums[i] == maxK)
                prevMax = i; 
            ans += max(0, min(prevMin, prevMax) - j);
        }
        return ans;
    }
};