class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(begin(nums), begin(nums) + k - 1, end(nums), greater<int>());
        return nums[k - 1];
    }
};