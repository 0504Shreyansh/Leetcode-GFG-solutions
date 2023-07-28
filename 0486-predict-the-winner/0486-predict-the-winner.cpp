class Solution {
private:
    int solve(int i, int j, vector<int>& nums, bool turn, vector<vector<vector<int>>>& dp) {
        if (i > j) return 0;
        if (dp[i][j][turn] != -1) return dp[i][j][turn];
        if (turn) {
            return dp[i][j][turn] = max(nums[i] + solve(i + 1, j, nums, !turn, dp), nums[j] + solve(i, j - 1, nums, !turn, dp));
        }
        return dp[i][j][turn] = min(solve(i + 1, j, nums, !turn, dp), solve(i, j - 1, nums, !turn, dp));
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int totalSum = 0;
        for (auto &it : nums) {
            totalSum += it;
        }
        vector<vector<vector<int>>> dp(20, 
                vector<vector<int>> (20, 
                    vector<int> (2, -1)));
        int sum1 = solve(0, nums.size() - 1, nums, 1, dp);
        int sum2 = totalSum - sum1;
        return sum1 >= sum2;
    }
};