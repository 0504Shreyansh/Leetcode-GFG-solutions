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
        if(dp[prev][mask] != -1) {
            return dp[prev][mask];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) continue;
            if(!isPerfectSquare(nums[prev], nums[i])) continue;
            ans += solve(i, mask | (1 << i), nums, dp);
        }
        return dp[prev][mask] = ans;
    }

public:
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        int mask = 0;
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int> ((1 << n + 1), -1));
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if(!(mask & (1 << i))) {  // starting point
                ans += solve(i, mask | (1 << i), nums, dp);
            }
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