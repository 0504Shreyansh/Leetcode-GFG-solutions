class Solution {
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
public:
    bool halvesAreAlike(string s) {
        int cnt1 = 0, cnt2 = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                if (i < n / 2) cnt1++;
                else cnt2++;
            }
        }
        return (cnt1 == cnt2);
    }
};