class Solution {
public:
    int maxScore(string s) {
        int ones = count(begin(s), end(s), '1');
        int ans = 0, n = s.size(), zeroes = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') zeroes++;
            else ones--;
            ans = max(ans, zeroes + ones);
        }
        return ans;
    }
};