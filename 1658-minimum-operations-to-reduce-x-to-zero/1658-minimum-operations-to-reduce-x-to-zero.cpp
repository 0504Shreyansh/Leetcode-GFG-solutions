class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (auto &it : nums) 
            sum += it;
        int curr = 0, res = 1e6, i = 0, n = nums.size();
        for (int j = 0; j < n; j++) {
            curr += nums[j];
            while (curr > sum - x && i <= j) 
                curr -= nums[i++];
            if (curr == sum - x) 
                res = min(res, n - (j - i + 1));
        }
        return (res == 1e6) ? -1 : res;
    }
};