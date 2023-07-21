class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        vector<int> count(N, 1);
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    } else if (dp[i] == 1 + dp[j]) {
                        count[i] += count[j];
                    }
                }
            }
        }
        int maxLength = 1;
        for (auto &len : dp) {
            maxLength = max(maxLength, len);
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (dp[i] == maxLength) {
                ans += count[i];
            }
        }
        return ans;
    }
};