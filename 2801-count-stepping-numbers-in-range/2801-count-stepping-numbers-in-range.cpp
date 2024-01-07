class Solution {
private:
    const int mod = 1e9 + 7;
    int solve(int i, int prev, bool tight, bool isLeadingZero, string &s, vector<vector<vector<vector<int>>>>& dp) {

        if (i >= s.size()) {
            return 1;
        }

        if (dp[i][tight][isLeadingZero][prev] != -1) {
            return dp[i][tight][isLeadingZero][prev];
        }

        int ans = 0;

        if (isLeadingZero) {
            int upperLimit = tight ? s[i] - '0' : 9;
            for (int d = 0; d <= upperLimit; d++) {
                bool nextLeadingZero = isLeadingZero && d == 0;
                bool nextTight = tight && s[i] - '0' == d;
                ans += solve(i + 1, d, nextTight, nextLeadingZero, s, dp);
                ans %= mod;
            }
        } 
        else {
            if (prev - 1 >= 0) {
                if (!tight || (tight && s[i] - '0' >= prev - 1)) {
                    ans += solve(i + 1, prev - 1, tight && s[i] - '0' == prev - 1, 0, s, dp);
                    ans %= mod;
                }
            }
            if (prev + 1 < 10) {
                if (!tight || (tight && s[i] - '0' >= prev + 1)) {
                    ans += solve(i + 1, prev + 1, tight && s[i] - '0' == prev + 1, 0, s, dp);
                    ans %= mod;
                }
            }
        }          

        return dp[i][tight][isLeadingZero][prev] = ans;   
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
    int countSteppingNumbers(string low, string high) {
        decreaseBy1(low);
        vector<vector<vector<vector<int>>>> dp(101, vector<vector<vector<int>>> (2, vector<vector<int>> (2, vector<int> (10, -1))));
        vector<vector<vector<vector<int>>>> dp2(101, vector<vector<vector<int>>> (2, vector<vector<int>> (2, vector<int> (10, -1))));
        int ans = solve(0, 0, true, true, low, dp);
        int ans2 = solve(0, 0, true, true, high, dp2);
        // cout << ans << ' ' << ans2 << endl;
        return (ans2 - ans + mod) % mod;
    }
};