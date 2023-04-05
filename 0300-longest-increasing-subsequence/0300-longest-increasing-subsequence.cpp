class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        int ans = 1;
        for(int i = 0; i < N; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] > nums[prev] && dp[i] < 1+dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};