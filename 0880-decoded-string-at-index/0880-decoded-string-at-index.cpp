class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long sz = 0;
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (isdigit(s[i])) 
                sz = sz * (s[i] - '0');
            else
                sz++;
        }
        string ans;
        for (int i = n - 1; i >= 0; i--) {
            k %= sz;
            if (k == 0 && isalpha(s[i])) 
                return (string) ""+s[i];
            if (isdigit(s[i]))
                sz /= (s[i] - '0');
            else
                sz--;
        }
        return s.substr(k,1);
    }
};