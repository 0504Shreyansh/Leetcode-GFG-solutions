class Solution {
private:
    int solve(int i, int j, vector<int>& nums, bool turn) {
        if (i > j) return 0;
        if (turn) {
            return max(nums[i] + solve(i + 1, j, nums, !turn), nums[j] + solve(i, j - 1, nums, !turn));
        }
        return min(solve(i + 1, j, nums, !turn), solve(i, j - 1, nums, !turn));
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int totalSum = 0;
        for (auto &it : nums) {
            totalSum += it;
        }
        int sum1 = solve(0, nums.size() - 1, nums, 1);
        int sum2 = totalSum - sum1;
        return sum1 >= sum2;
    }
};