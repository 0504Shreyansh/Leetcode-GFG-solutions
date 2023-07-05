class Solution {
public:
    bool isPerfectSquare(int a, int b) {
        int sqroot = sqrt(a + b);
        return sqroot * sqroot == (a + b);
    }

    int solve(int prev, int mask, vector<int>& nums, vector<vector<int>>& dp) {
        if(mask == (1 << (int)nums.size()) - 1) {
            return 1;
        }
        if(dp[prev][mask] != -1) {
            return dp[prev][mask];
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(!(mask & (1 << i)) && isPerfectSquare(nums[prev], nums[i])) {
                ans += solve(i, mask | (1 << i), nums, dp);
            }
        }
        return dp[prev][mask] = ans;
    }

    int numSquarefulPerms(vector<int>& nums) {

        unordered_map<int, int> freq;
        for(auto &x : nums) freq[x]++;
        int mask = 0;
        int ans = 0;
        vector<vector<int>> dp(nums.size() + 1, vector<int> ((1 << nums.size() + 1), -1));
        for(int i = 0; i < nums.size(); i++) {
            if(!(mask & (1 << i))) {
                ans += solve(i, mask | (1 << i), nums, dp);
            }
        }
        vector<int> fact(13, 1);
        for(int i = 1; i <= 12; ++i) {
            fact[i] = i * fact[i - 1];
        }
        for(auto &it : freq) {
            ans /= fact[it.second];
            // cout << fact[freq[nums[i]]] << endl;
        }
        return ans;
    }
};