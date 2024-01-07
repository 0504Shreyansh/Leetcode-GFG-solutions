class Solution {
private:
    int solve(int i, bool tight, bool isLeadingZero, int mask, string &s, vector<vector<vector<vector<int>>>>& dp) {
        if (i >= s.size()) {
            return 1;
        }
        
        if (dp[i][tight][isLeadingZero][mask] != -1) {
            return dp[i][tight][isLeadingZero][mask];
        }
        
        int ans = 0;
        int upperLimit = tight ? s[i] - '0' : 9;
        for (int d = 0; d <= upperLimit; d++) {
            bool nextLeadingZero = isLeadingZero && d == 0;
            bool nextTight = tight && s[i] - '0' == d;
            
            if (nextLeadingZero) {
                ans += solve(i + 1, nextTight, nextLeadingZero, mask, s, dp);
            }
            else {
                if (mask & (1 << d)) continue;
                ans += solve(i + 1, nextTight, nextLeadingZero, mask | (1 << d), s, dp);
            }
        }
        
        return dp[i][tight][isLeadingZero][mask] = ans;
    }
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        vector<vector<vector<vector<int>>>> dp(10, vector<vector<vector<int>>> (2, vector<vector<int>> (2, vector<int> (1025, -1))));
        // because it counts 0 also
        return solve(0, true, true, 0, s, dp) - 1;
    }
};