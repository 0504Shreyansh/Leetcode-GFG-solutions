class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int zeroIndex = -1;
        int negIndex = -1;
        int negCount = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(nums[i] == 0) {
                zeroIndex = i;
                negIndex = -1;
                negCount = 0;
            } else if(nums[i] < 0) {
                ++negCount;
                if(negCount == 1) {
                    negIndex = i;
                }
            }
            if(negCount % 2 == 0) {
                if(zeroIndex == -1) {
                    ans = max(ans, i + 1);
                } else {
                    ans = max(ans, i - zeroIndex);
                }
            } else {   
                ans = max(ans, i - negIndex);
            }        
        }
        return ans;
    }
};