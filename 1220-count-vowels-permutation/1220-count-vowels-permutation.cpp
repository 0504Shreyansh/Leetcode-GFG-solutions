class Solution {
private:
    const int mod = 1e9 + 7;
    int solve(int i, int n, char prev, vector<vector<int>>& dp) {
        if (i >= n) return 1;
        if (dp[i][prev - 'a'] != -1) return dp[i][prev - 'a'];
        if (prev == 'z') {
            return dp[i][prev - 'a'] = ((((solve(i + 1, n, 'a', dp) + solve(i + 1, n, 'e', dp)) % mod + solve(i + 1, n, 'i', dp)) % mod + solve(i + 1, n, 'o', dp)) % mod + solve(i + 1, n, 'u', dp)) % mod;
        }
        if (prev == 'a') {
            return dp[i][prev - 'a'] = solve(i + 1, n, 'e', dp);
        }
        if (prev == 'e') {
            return dp[i][prev - 'a'] = (solve(i + 1, n, 'a', dp) + solve(i + 1, n, 'i', dp)) % mod;
        }
        if (prev == 'i') {
            return dp[i][prev - 'a'] = (((solve(i + 1, n, 'a', dp) + solve(i + 1, n, 'e', dp)) % mod + solve(i + 1, n, 'o', dp)) % mod + solve(i + 1, n, 'u', dp)) % mod;
        }
        if (prev == 'o') {
            return dp[i][prev - 'a'] = (solve(i + 1, n, 'i', dp) + solve(i + 1, n, 'u', dp)) % mod;
        }
        return dp[i][prev - 'a'] = solve(i + 1, n, 'a', dp);
    }
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int> (26, -1));
        return solve(0, n, 'z', dp);
    }
};