class Solution {
public:
    int solve(int i, int mask, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        int n = nums1.size();
        if(i >= n) {
            return 0;
        }
        if(dp[i][mask] != -1) {
            return dp[i][mask];
        }
        int ans = INT_MAX;
        for(int j = 0; j < n; ++j) {
            if(((mask >> j) & 1) == 0) {
                int curr = (nums1[i] ^ nums2[j]) + solve(i + 1, mask | (1 << j), nums1, nums2, dp);
                ans = min(ans, curr);
            }
        }
        return dp[i][mask] = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int> (1 << nums1.size(), -1));
        return solve(0, 0, nums1, nums2, dp);
    }
};