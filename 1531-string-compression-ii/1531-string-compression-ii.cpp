class Solution {
private:
    int getLength(int count) {
        return (count == 1) ? 1 : ((count < 10) ? 2 : (count < 100) ? 3 : 4);
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int N = s.size();
        vector<vector<int>> dp(N + 1, vector<int> (k + 1));
        for (int i = N; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                // base case
                if (i == N) {
                    dp[N][j] = 0;
                    continue;
                }
                // delete one char
                dp[i][j] = (j > 0) ? dp[i + 1][j - 1] : 2e9;
                
                int del = j, count = 0;
                for (int end = i; end < N && del >= 0; end++) {
                    if (s[end] == s[i]) {
                        count++;
                        dp[i][j] = min(dp[i][j], getLength(count) + dp[end + 1][del]);
                    } else {
                        del--;
                    }
                }
            }
        }
        return dp[0][k];
    }
};