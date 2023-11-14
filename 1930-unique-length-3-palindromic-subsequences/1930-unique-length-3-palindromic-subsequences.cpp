class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        int n = s.size();
        for (char c = 'a'; c <= 'z'; c++) {
            int i = 0, j = n - 1;
            for ( ; i < n && s[i] != c; ++i);
            if (i == n) continue;
            for ( ; j >= 0 && s[j] != c; --j);
            unordered_set<char> seen;
            i++, j--;
            while (i <= j) {
                seen.insert(s[i++]);
            }
            ans += (int)seen.size();
        }
        return ans;
    }
};