class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int N = s1.size();
        int M = s2.size();
        int sum1 = 0;
        int sum2 = 0;
        for (auto &it : s1) sum1 += it;
        for (auto &it : s2) sum2 += it;
        vector<vector<int>> dp(N + 1, vector<int> (M + 1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = int(s1[i - 1]) + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int delCost1 = sum1 - dp[N][M];
        int delCost2 = sum2 - dp[N][M];
        return delCost1 + delCost2;
    }
};