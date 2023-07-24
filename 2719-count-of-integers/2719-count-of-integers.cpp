class Solution {
private:
    const int mod = 1e9 + 7;
    int solve(int i, string &s, int sum, int min_sum, int max_sum, bool tight, vector<vector<vector<int>>>& dp) {
        if (i >= s.size()) {
            return (min_sum <= sum && sum <= max_sum);
        } 
        if (dp[i][tight][sum] != -1) {
            return dp[i][tight][sum];
        }
        char upperLimit = (tight) ? s[i] : '9';
        int ans = 0;
        for (char c = '0'; c <= upperLimit; c++) {
            ans += solve(i + 1, s, sum + (c - '0'), min_sum, max_sum, tight && (c == upperLimit), dp);
            ans %= mod;
        }
        return dp[i][tight][sum] = ans;
    }
    void decreaseBy1(string &s) {
        int i = s.size() - 1;
        while (s[i] == '0') {
            s[i] = '9';
            i--;
        }
        s[i] --;
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        decreaseBy1(num1);
        vector<vector<vector<int>>> dp(23, 
            vector<vector<int>> (2, 
                    vector<int> (220, -1)));
        vector<vector<vector<int>>> dp2(23, 
            vector<vector<int>> (2, 
                    vector<int> (220, -1)));
        return (solve(0, num2, 0, min_sum, max_sum, true, dp) - solve(0, num1, 0, min_sum, max_sum, true, dp2) + mod) % mod;
    }
};