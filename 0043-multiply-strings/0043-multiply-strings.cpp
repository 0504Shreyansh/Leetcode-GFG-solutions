class Solution {
public:
    string multiply(string s, string p) {
        if (s == "0" || p == "0") return "0";
        int n = s.size(), m = p.size();
        vector<int> A(n + m, 0);
        for (int j = m - 1; j >= 0; j--) {
            int carry = 0;
            for (int i = n - 1; i >= 0; i--) {
                A[i + j + 1] += (s[i] - '0') * (p[j] - '0') + carry;
                carry = A[i + j + 1] / 10;
                A[i + j + 1] %= 10;
            }
            if (carry != 0) {
                A[j] += carry;
            }
        }
        bool zeroes = true;
        string res;
        for (auto &it : A) {
            if (zeroes && it == 0) continue;
            zeroes = false;
            res += it + '0';
        }
        return res;
    }
};