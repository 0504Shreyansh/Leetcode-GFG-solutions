class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if(nums[i] == INT_MIN) {
                i++;
                continue;
            }
            int pos = nums[i] - 1;
            if (pos >= 0 && pos < n && nums[i] != nums[pos]) {
                swap(nums[i], nums[pos]);
            } else {
                i++;   
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};