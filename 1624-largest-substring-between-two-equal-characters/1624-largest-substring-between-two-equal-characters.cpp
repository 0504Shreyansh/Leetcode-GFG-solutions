class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), ans = -1;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int first = -1, last = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == ch) {
                    if (first == -1) first = i;
                    last = i;
                }
            }
            ans = max(ans, last - first - 1);
        }
        return ans;
    }
};