class Solution {
private:
    int solve(int i, int n, int mask, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if (i >= n) return 0;
        if (dp[i][mask] != -1) return dp[i][mask];
        int ans = 1e9;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) continue;
            ans = min(ans, (nums1[i] ^ nums2[j]) + solve(i + 1, n, mask | (1 << j), nums1, nums2, dp));
        }
        return dp[i][mask] = ans;
    }
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(1<<n, -1));
        return solve(0, n, 0, nums1, nums2, dp);
    }
};