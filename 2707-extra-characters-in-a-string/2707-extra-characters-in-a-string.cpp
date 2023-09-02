class Solution {
private:
    int solve(int i, int N, string &s, set<string>& available, vector<int>& dp) {
        if (i >= N) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = 1 + solve(i + 1, N, s, available, dp);
        string c;
        for (int j = i; j < N; j++) {
            c += s[j];
            if (available.count(c)) {
                ans = min(ans, solve(j + 1, N, s, available, dp));
            }
        }
        return dp[i] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> available(begin(dictionary), end(dictionary));
        int N = s.size();
        vector<int> dp(N + 1);
        // return solve(0, N, s, available, dp);
        dp[N] = 0;
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