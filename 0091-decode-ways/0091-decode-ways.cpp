class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        vector<int> dp(N + 1);
        dp[N] = 1;
        for (int i = N - 1; i >= 0; i--) {
            if (1 <= s[i] - '0' && s[i] - '0' <= 9) {
                dp[i] += dp[i + 1];
            }
            if (i + 1 < N && 10 <= stoi(s.substr(i, 2)) && stoi(s.substr(i, 2)) <= 26) {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};