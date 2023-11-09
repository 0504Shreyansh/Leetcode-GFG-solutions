class Solution {
public:
    int countHomogenous(string s) {
        const int mod = 1e9 + 7;
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[i] == s[j]) ++j;
            long long len = j - i;
            ans += ((len * (len + 1)) / 2) % mod;
            i = j - 1;
        }
        return ans;
    }
};