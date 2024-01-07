class Solution {
private:
    const int mod = 1e9 + 7;
    int solve(int i, int sum, bool tight, string &s, int min_sum, int max_sum, vector<vector<vector<int>>>& dp) {
        if (i >= s.size()) {
            return (min_sum <= sum && sum <= max_sum);
        }

        if (dp[i][sum][tight] != -1) {
            return dp[i][sum][tight];
        }
        
        int ans = 0;
        int upperLimit = tight ? s[i] - '0' : 9;
        for (int d = 0; d <= upperLimit; d++) {
            ans += solve(i + 1, sum + d, tight && d == s[i] - '0', s, min_sum, max_sum, dp);
            ans %= mod;
        }
        
        return dp[i][sum][tight] = ans;
    }
    void decreaseBy1(string &s) {
        int i = s.size() - 1;
        while (i >= 0) {
            if (s[i] == '0') {
                s[i] = '9';
                i--;
            } else {
                s[i]--;
                break;
            }
        }
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        decreaseBy1(num1);
        vector<vector<vector<int>>> dp(23, vector<vector<int>> (210, vector<int> (2, -1)));
        vector<vector<vector<int>>> dp2(23, vector<vector<int>> (210, vector<int> (2, -1)));
        int ans = solve(0, 0, 1, num1, min_sum, max_sum, dp);
        int ans2 = solve(0, 0, 1, num2, min_sum, max_sum, dp2);
        return (ans2 - ans + mod) % mod;
    }
};