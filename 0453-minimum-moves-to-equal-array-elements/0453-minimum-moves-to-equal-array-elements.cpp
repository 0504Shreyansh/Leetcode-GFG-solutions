class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for (auto &it : nums) {
            mini = min(mini, it);
        }
        int ans = 0;
        for (auto &it : nums) {
            ans += (it - mini);
        }
        return ans;
    }
};