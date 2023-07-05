class Solution {
private:
    bool isPerfectSquare(int a, int b) {
        int sqroot = sqrt(a + b);
        return sqroot * sqroot == (a + b);
    }

    int solve(int prev, int mask, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(mask == (1 << n) - 1) {
            return 1;
        }
        if(dp[prev + 1][mask] != -1) {
            return dp[prev + 1][mask];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(prev == -1) {
                ans += solve(i, mask | (1 << i), nums, dp);
            } else if(!(mask & (1 << i)) && isPerfectSquare(nums[prev], nums[i])) {
                ans += solve(i, mask | (1 << i), nums, dp);
            }
        }
        return dp[prev + 1][mask] = ans;
    }

public:
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> ((1 << n), -1));
        int ans = solve(-1, 0, nums, dp);
        unordered_map<int, int> freq;
        for(auto &it : nums) {
            freq[it]++;
        }
        vector<int> fact(13, 1);
        for(int i = 2; i <= 12; ++i) {
            fact[i] = i * fact[i - 1];
        }
        for(auto &it : freq) {  // decrease the repeated count
            ans /= fact[it.second];
        }
        return ans;
    }
};