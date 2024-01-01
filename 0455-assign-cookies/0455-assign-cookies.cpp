class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int i = 0, j = 0, N = g.size(), M = s.size(), ans = 0;
        while (i < N && j < M) {
            if (s[j] >= g[i]) {
                ans++;
                i++, j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};