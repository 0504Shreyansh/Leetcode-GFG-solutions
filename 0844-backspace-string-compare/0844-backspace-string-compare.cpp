class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;
        int n = s.size(), m = t.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                if (a.size()) a.pop_back();
            } else {
                a += s[i];
            }
        }
        for (int i = 0; i < m; i++) {
            if (t[i] == '#') {
                if (b.size()) b.pop_back();
            } else {
                b += t[i];
            }
        }
        return (a == b);
    }
};