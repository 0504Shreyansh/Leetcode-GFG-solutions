class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        /*1 1 1 1 --> 4 1 1 4*/
        /*4 1 1 4 0 3 1 3 --> 1 + 3 + 4*/
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            // mark the starting and ending index to the 
            // size of corresponding size of chunk of 1's
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
        // look for (non-zero 0 non-zero) for maximum size
        for(int i = 1; i < n - 1; i++) {
            if(nums[i] == 0) {
                res = max(res, nums[i - 1] + nums[i + 1]);
            }
        }
        if(res == n) res--;
        return res;
    }
};