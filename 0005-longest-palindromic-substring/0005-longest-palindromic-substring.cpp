class Solution {
public:
    int check(string &s, int l, int r) {
        while(l >= 0 && r < s.length() && s[l] == s[r])
            l--, r++;
        return r - l - 1;
    }

    string longestPalindrome(string s) {
        
        int end = 0, st = 0;
        for(int i = 0; i<s.size(); i++) {
            int len1 = check(s, i, i);
            int len2 = check(s, i , i+1);
            int len = max(len1, len2);
            if(len > end) {
                end = len;
                st = i - (len - 1)/2;
            } 
        }
        return s.substr(st, end);
        
    }
};