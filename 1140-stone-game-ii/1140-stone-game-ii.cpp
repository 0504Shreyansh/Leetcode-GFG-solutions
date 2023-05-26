class Solution {
public:
    int solve(vector<int>& piles, int i, int m, int total, vector<vector<int>>& dp) {
        int n = piles.size();
        if(dp[i][m] != -1) return dp[i][m];
        int res = 0, taken = 0;
        for(int j = i; j < min(i + 2 * m, n); j++) {
            taken += piles[j];
            res = max(res, total - solve(piles, j + 1, max(m, j - i + 1), total - taken, dp));
        }
        return dp[i][m] = res;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int> (2*n + 1, -1));
        return solve(piles, 0, 1, accumulate(begin(piles),end(piles),0), dp);
    }
};