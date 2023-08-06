class Solution {
private:
    const int mod = 1e9 + 7;
    int solve(int n, int l, int N, int L, int K, vector<vector<int>>& dp) {
        if (n > N) return 0;
        if (l == L) return (N == n);
        if (dp[n][l] != -1) return dp[n][l];
        // picking from used -> if less than k songs already picked --> 0
        // if more than k songs have been picked --> (n - k) different possibilities
        int pickUsed = (max(0, n - K) * 1ll * solve(n, l + 1, N, L, K, dp)) % mod;
        // pick from unused --> (N - n) different possibilities
        int pickUnUsed = ((N - n) * 1ll * solve(n + 1, l + 1, N, L, K, dp)) % mod;
        return dp[n][l] = (pickUsed + pickUnUsed) % mod;
    }
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<int>> dp(N + 1, vector<int> (L + 1, -1));
        return solve(0, 0, N, L, K, dp);
    }
};