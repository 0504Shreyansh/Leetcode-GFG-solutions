class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size();
        string ans;
        vector<int> taken(n);
        for (auto &x : order) {
            for (int i = 0; i < n; i++) {
                if (x == s[i]) {
                    ans += x;
                    taken[i] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!taken[i]) ans += s[i];
        }
        return ans;
    }
};