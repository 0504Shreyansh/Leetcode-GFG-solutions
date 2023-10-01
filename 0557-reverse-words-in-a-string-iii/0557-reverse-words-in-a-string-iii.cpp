class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        // s += ' ';
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[j] != ' ') j++;
            string r(s.substr(i, j - i));
            reverse(begin(r), end(r));
            for (int k = i; k < j; k++)
                s[k] = r[k - i];
            i = j; 
        }
        return s;
    }
};