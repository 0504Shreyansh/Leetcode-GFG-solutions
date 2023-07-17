class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int zeroIndex = -1;
        int negIndex = -1;
        int negCount = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(nums[i] == 0) {  // restore the count and index of -ve number
                zeroIndex = i;
                negIndex = -1;
                negCount = 0;
            } else if(nums[i] < 0) {
                ++negCount;  // first index of -ve number
                if(negCount == 1) {
                    negIndex = i;
                }
            }
            // main logic 
            if(negCount % 2 == 0) {
                if(zeroIndex == -1) {  // even -ve nums + no 0's
                    ans = max(ans, i + 1);
                } else {    // even -ve nums + 0 found
                    ans = max(ans, i - zeroIndex);
                }
            } else {     // odd -ve nums found --> zeroIndex < negIndex
                ans = max(ans, i - negIndex);
            }        
        }
        return ans;
    }
};