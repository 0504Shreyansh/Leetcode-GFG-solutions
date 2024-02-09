class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        if (n == 1) return nums;
        vector<int> dp(n, 1);
        vector<int> store(n, -1);
        int maxLength = 0, idx = -1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    store[i] = j;
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                idx = i;
            }
        }
        
        vector<int> ans = {nums[idx]};
        while (store[idx] != -1) {
            ans.push_back(nums[store[idx]]);
            idx = store[idx];
        }
        return ans;
    }
};