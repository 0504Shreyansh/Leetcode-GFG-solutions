class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        long long sum = accumulate(begin(nums), end(nums), 0LL);
        int n = nums.size();
        for (int i = n - 1; i >= 2; i--) {
            sum -= nums[i];
            if (nums[i] < sum) {
                return sum + nums[i];
            }
        }
        return -1;
    }
};