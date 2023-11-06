class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        for (auto &x : nums)
            count[x]++;
        int minOcc = 1e5 + 1;
        for (auto &x : count)
            minOcc = min(minOcc, x.second);
        int ans = 1e6;
        for (int g = 1; g <= minOcc; g++) {
            int cnt = 0;
            bool impossible = 0;
            for (auto &it : count) {
                int freq = it.second;
                int a = freq / (g + 1);
                int b = freq % (g + 1);
                if (b == 0) {
                    cnt += a;
                } else if (g - b <= a) {
                    cnt += a + 1;
                } else {
                    impossible = 1;
                    break;
                }
            }
            if (!impossible) {
                ans = min(ans, cnt);
            }
        }
        return ans;
    }
};