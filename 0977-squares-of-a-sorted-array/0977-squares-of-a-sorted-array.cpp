class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int minIndex = -1, minValue = 1e5, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (minValue > abs(nums[i])) {
                minValue = abs(nums[i]);
                minIndex = i;
            }
        }
        int i = minIndex, j = minIndex + 1;
        while (i >= 0 && j < n) {
            if (abs(nums[i]) <= abs(nums[j])) {
                ans.push_back(nums[i] * nums[i]);
                --i;
            } else {
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
        }
        while (i >= 0) {
            ans.push_back(nums[i] * nums[i]);
            --i;
        }
        while (j < n) {
            ans.push_back(nums[j] * nums[j]);
            ++j;
        }
        return ans;
    }
};