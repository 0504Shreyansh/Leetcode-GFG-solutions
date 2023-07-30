class Solution {
private:
    int f(int l, int r, string &s, vector<vector<int>>& dp) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int res = 1 + f(l + 1, r, s, dp);  // delete only one char
        for (int i = l+1; i <= r; i++) {
            if (s[l] == s[i]) {  
                // find delete operation for [l+1...i-1] + [i...r] substring
                res = min(res, f(l, i-1, s, dp) + f(1+i, r, s, dp));
            }
        }
        return dp[l][r] = res;
    }
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(0, n - 1, s, dp);
    }
};