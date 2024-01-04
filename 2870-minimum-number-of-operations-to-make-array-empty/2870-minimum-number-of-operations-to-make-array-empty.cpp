class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> count;
        for (auto &it : nums) {
            count[it]++;
        }
        int ans = 0;
        for (auto &[value, freq] : count) {
            if (freq == 1) return -1;
            if (freq % 3 == 0) {
                ans += (freq / 3);
            } else if (freq % 3 == 2) {
                ans += 1 + ((freq - 2) / 3);
            } else {
                ans += 2 + ((freq - 4) / 3);
            }
        }
        return ans;
    }
};