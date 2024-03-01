class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string res;
        int c0 = 0, c1 = 0;
        for (auto &it : s) {
            if (it == '0') c0++;
            else c1++;
        }
        while (--c1) res += '1';
        while (c0--) res += '0';
        res += '1';
        return res;
    }
};