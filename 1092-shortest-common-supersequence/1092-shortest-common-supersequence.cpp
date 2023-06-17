class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i - 1] == t[j - 1]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp);
        }
        return dp[i][j] = 0 + max(solve(i - 1, j, s, t, dp), solve(i, j - 1, s, t, dp));
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        int curr = solve(n, m, str1, str2, dp);
        int i = n, j = m;
        string ans;
        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--, j--;
            }
            else {
                if(dp[i - 1][j] >= dp[i][j - 1]) {
                    ans += str1[i - 1];
                    i--;
                }
                else {
                    ans += str2[j - 1];
                    j--;
                }
            }
        }
        while(i > 0) {
            ans += str1[i - 1];
            i--;
        }
        while(j > 0) {
            ans += str2[j - 1];
            j--;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};