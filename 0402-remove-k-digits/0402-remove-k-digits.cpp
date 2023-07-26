class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for (auto &it : num) {
            while (k && ans.size() && ans.back() > it) {
                k--;
                ans.pop_back();
            }
            if (ans.size() == 0 && it == '0') {
                continue;
            } else {
                ans += it;
            }
            while (k && ans.size() && ans.back() == '0') {
                k--;
                ans.pop_back();
            }
        }
        while (k && ans.size()) {
            k--;
            ans.pop_back();
        }
        return ans.size() ? ans : "0";
    }
};