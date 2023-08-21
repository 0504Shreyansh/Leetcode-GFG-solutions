class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string c;
        for (int i = 0; i < n; i++) {
            c += s[i];
            if (n % (int)c.size() == 0) {
                bool f = true;
                int j = i + 1;
                int m = c.size();
                bool entered = false;
                while (j + m <= n && s.substr(j, m) == c) {
                    entered = true;
                    j += m;
                }
                if (entered && j >= n) return true;
            }
        }
        return false;
    }
};