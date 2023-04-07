class Solution {
public:
    int solver(vector<int>& nums, int target, vector<int>& dp) {
        if(target==0) {
            return 1;
        }
        if(dp[target] != -1) {
            return dp[target];
        }
        int ans = 0;
        for(auto cur : nums) {
            if(target >= cur) {
                ans += solver(nums, target-cur, dp);
            }
        }   
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<long> dp(target+1, 0);
        // return solver(nums, target, dp);
        dp[0] = 1;
        for(int t = 1; t <= target; t++) {
            unsigned long long val = 0;
            for(auto cur : nums) {
                if(t >= cur) 
                    val += dp[t-cur];
            }
            dp[t] = val;
        }
        return dp[target];
    }
};