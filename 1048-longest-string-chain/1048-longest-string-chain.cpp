class Solution {
private:
    bool isSubsequence(string &s, string &p) {
        int i = 0, j = 0, n = s.size(), m = p.size();
        bool diff = false;
        while (i < n && j < m) {
            if (s[i] == p[j]) i++, j++;
            else if (diff == false) diff = true, j++;
            else return false;
        }
        return (diff == false || (i == n && j == m));
    }
    int solve(int prev, int i, vector<string>& words, vector<vector<int>>& dp) {
        if (i >= words.size()) return 0;
        if (dp[i][prev] != -1) return dp[i][prev];
        int notPick = solve(prev, i + 1, words, dp), pick = 0;
        if (words[prev].size() == words[i].size() - 1 && isSubsequence(words[prev], words[i])) {
            pick = 1 + solve(i, i + 1, words, dp);
        }
        return dp[i][prev] = max(pick, notPick);
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), [&](auto &a, auto &b) {
            return a.size() < b.size();
        });
        int n = words.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int longest = 1;
        for (int i = 0; i < n; i++) {
            longest = max(longest, 1 + solve(i, i + 1, words, dp));
        }
        return longest;
    }
};