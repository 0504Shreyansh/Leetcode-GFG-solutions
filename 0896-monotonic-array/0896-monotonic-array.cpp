class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = (nums.back() >= nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1] && !increasing) return false;
            if (nums[i] < nums[i - 1] && increasing) return false;
        }
        return true;
    }
};