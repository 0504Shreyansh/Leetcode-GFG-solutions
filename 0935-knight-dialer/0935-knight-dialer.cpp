class Solution {
private:
    const int mod = 1e9 + 7;
    vector<vector<int>> next = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, 
                                     {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
    int solve(int digit, int n, vector<vector<int>>& dp) {
        if (n == 0) return 1;
        if (dp[digit][n] != -1) return dp[digit][n];
        dp[digit][n] = 0;
        for (int &d : next[digit]) 
            (dp[digit][n] += solve(d, n - 1, dp)) %= mod;
        return dp[digit][n];
    }
public:
    int knightDialer(int n) {
        vector<vector<int>> dp(10, vector<int> (n + 1, -1));
        int ans = 0;
        for (int d = 0; d < 10; d++) 
            (ans += solve(d, n - 1, dp)) %= mod;
        return ans;
    }
};