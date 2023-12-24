class Solution {
public:
    int minOperations(string s) {
        string t1, t2;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                t1 += '0';
                t2 += '1';
            } else {
                t1 += '1';
                t2 += '0';
            }
        }
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++) {
            ans1 += (s[i] != t1[i]);
            ans2 += (s[i] != t2[i]);
        }
        return min(ans1, ans2);
    }
};