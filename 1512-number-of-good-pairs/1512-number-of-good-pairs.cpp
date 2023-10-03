class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> count(101, 0);
        for (auto &it : nums)
            count[it]++;
        int ans = 0;
        for (auto &it : count) {
            ans += (it * (it - 1)) / 2;
        }
        return ans;
    }
};