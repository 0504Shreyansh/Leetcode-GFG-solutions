// IT IS ALMOST SAME AS LEETCODE 44. WILDCARD MATCHING
class Solution {
public:
    bool isMatchRecurs(string& s, string &p, int i, int j, vector<vector<int>> &dp) {
        
        if (j == p.size() && i == s.size()) 
            return true;
        
        if (j == p.size())
            return false;

        if (dp[i][j] != -1) 
            return dp[i][j];

        bool firstMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');
        bool ans;
        if (j+1 < p.size() && p[j+1] == '*') {
            // Take or leave
            ans = isMatchRecurs(s, p, i, j+2, dp) || firstMatch && isMatchRecurs(s, p, i+1, j, dp);
        }
        else {
            ans = firstMatch && isMatchRecurs(s, p, i+1, j+1, dp);
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return isMatchRecurs(s, p, 0, 0, dp);        
    }
};