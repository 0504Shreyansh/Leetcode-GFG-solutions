class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                int index = i;
                while(index < n && nums[index] == 1) {
                    index++;
                }
                index--;
                int len = index - i + 1;
                res = max(res, len);
                nums[i] = nums[index] = len;
                if(i < index) i = index;
            }
        }
        for(int i = 1; i < n - 1; i++) {
            if(nums[i] == 0) {
                res = max(res, nums[i - 1] + nums[i + 1]);
            }
        }
        if(res == n) res--;
        return res;
    }
};