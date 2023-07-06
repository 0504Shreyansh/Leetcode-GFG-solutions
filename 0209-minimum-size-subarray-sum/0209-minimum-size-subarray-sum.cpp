class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int sum = 0;
        int res = INT_MAX;
        for(int j = 0; j < n; j++) {
            sum += nums[j];
            while(sum >= target && i <= j) {
                res = min(res, j - i + 1);
                sum -= nums[i++];
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};