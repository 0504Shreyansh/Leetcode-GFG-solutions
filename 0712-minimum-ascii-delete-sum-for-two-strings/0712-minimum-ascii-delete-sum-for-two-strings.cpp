class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int N = s1.size();
        int M = s2.size();
        int sum1 = 0;
        int sum2 = 0;
        for (auto &it : s1) sum1 += it;
        for (auto &it : s2) sum2 += it;
        vector<int> dp(M + 1, 0), prev(M + 1, 0);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = int(s1[i - 1]) + prev[j - 1];
                } else {
                    dp[j] = max(prev[j], dp[j - 1]);
                }
            }
            prev = dp;
        }
        int delCost1 = sum1 - dp[M];
        int delCost2 = sum2 - dp[M];
        return delCost1 + delCost2;
    }
};