class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        long long sum = accumulate(begin(nums), end(nums), 0LL);
        for (int i = n - 1; i >= 2; i--) {
            sum -= nums[i];
            if (sum > nums[i]) {
                return sum + nums[i];
            } 
            
        }
        return -1;
    }
};