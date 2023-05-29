class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Burst from last and calculate coins
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));
        
        for(int i = n; i >= 1; i--) {
            for(int j = 1; j <= n; j++) {
                if(i > j) continue;
                for(int k = i; k <= j; k++) {
                    int currCoins = (nums[i - 1] * nums[k] * nums[j + 1]) + dp[i][k - 1] + dp[k + 1][j];
                    dp[i][j] = max(dp[i][j], currCoins);
                }
            }
        }
        return dp[1][n];
    }
};