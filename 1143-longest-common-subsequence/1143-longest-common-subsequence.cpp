class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> prev(m + 1), curr(m + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                curr[j] = (text1[i - 1] == text2[j - 1]) ? 1 + prev[j - 1] : max(curr[j - 1], prev[j]);
            }
            prev = curr;
        } 
        return curr[m];
    }
};