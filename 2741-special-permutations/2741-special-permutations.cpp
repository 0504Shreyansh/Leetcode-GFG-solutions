class Solution {
private:
    const int mod = 1e9 + 7;
    int solve(int prev, int mask, vector<int>& nums, vector<vector<int>>& dp) {
        if(mask == (1 << (int)nums.size()) - 1) {
            return 1;
        }
        if(dp[prev + 1][mask] != -1) {
            return dp[prev + 1][mask];
        }
        int ans = 0;
        for(int j = 0; j < nums.size(); ++j) {
            if(prev == -1) {
                ans += solve(j, mask | (1 << j), nums, dp);
                ans %= 1000000007;
            } else if(!(mask & (1 << j)) && (nums[j] % nums[prev] == 0 || nums[prev] % nums[j] == 0)) {
                ans += solve(j, mask | (1 << j), nums, dp);
                ans %= 1000000007;
            }
        }
        return dp[prev + 1][mask] = ans;
    }

public:
    int specialPerm(vector<int>& nums) {
        vector<vector<int>> dp(16, 
                vector<int> ((1 << nums.size()), -1));
        return solve(-1, 0, nums, dp);
    }
};