class Solution {
private:
    int solve(int i, int amount, vector<int>& coins) {
        if (i >= coins.size()) return (amount == 0);
        int notPick = solve(i + 1, amount, coins);
        int pick = 0;
        if (amount >= coins[i])
            pick = solve(i, amount - coins[i], coins);
        return pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<vector<int>> dp(N+1, vector<int> (amount+1, 0));
        dp[N][0] = 1;
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                int notPick = dp[i + 1][j];
                int pick = 0;
                if (j >= coins[i]) 
                    pick = dp[i][j - coins[i]];
                dp[i][j] = pick + notPick;
            }
        }
        return dp[0][amount];
    }
};