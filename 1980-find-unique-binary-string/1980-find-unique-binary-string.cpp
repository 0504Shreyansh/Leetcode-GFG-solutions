class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums.size();
        for (int i = 0; i < (1 << n); ++i) {
            string s;
            for (int j = 0; j < n; j++) {
                s += ((i >> j) & 1) + '0';
            }
            bool found = false;
            for (auto &it : nums) {
                if (s == it) {
                    found = true;
                    break;
                }
            }
            if (!found) return s;
        }
        return "";
    }
};