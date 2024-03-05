class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) {
            char same = s[i];
            while (i <= j && same == s[i]) ++i;
            while (i < j && same == s[j]) --j;
            while (i < j && s[j] == same) --j;
        }
        return j - i + 1;
    }
};