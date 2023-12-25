class Solution {
public:
    int numDecodings(string s) {
        int N = s.size(), a = 0, b = 1, c = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (1 <= s[i] - '0' && s[i] - '0' <= 9) {
                a += b;
            }
            if (i + 1 < N && 10 <= stoi(s.substr(i, 2)) && stoi(s.substr(i, 2)) <= 26) {
                a += c;
            }
            c = b, b = a, a = 0;
        }
        return b;
    }
};

/*
dpi, dpi+1, dpi+2 --> a, b, c
*/