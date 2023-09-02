class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> available(begin(dictionary), end(dictionary));
        int N = s.size();
        vector<int> dp(N + 1);
        for (int i = N - 1; i >= 0; i--) {
            string c;
            int ans = 1 + dp[i + 1];
            for (int j = i; j < N; j++) {
                c += s[j];
                if (available.count(c)) {
                    ans = min(ans, dp[j + 1]);
                }
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};