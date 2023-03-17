class Solution {
public:
    /*Method 1 : Recusion
    int recSol(int i, int n, vector<int>& coins, int amount) {
        if(i==0) return (amount%coins[0]==0) ? (amount/coins[0]) : 1e9;
        int notTake = recSol(i-1, n, coins, amount), take = 1e9;
        if(amount >= coins[i]) take = 1 + recSol(i, n, coins, amount-coins[i]);
        return min(take, notTake);
    }*/

    /*Method 2 : Memoization
    int memoizedSol(int i, int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(i==0) return (amount%coins[0]==0) ? dp[i][amount] = (amount/coins[0]) : 1e9;
        if(dp[i][amount] != 1e9) return dp[i][amount];
        int notTake = memoizedSol(i-1, n, coins, amount, dp), take = 1e9;
        if(amount >= coins[i]) take =  1 + memoizedSol(i, n, coins, amount-coins[i], dp);
        return dp[i][amount] = min(take, notTake);
    }*/

    /*Method 3 : Tabulation
    int tabulatedSol(int n, vector<int>& coins, int amount) {
        vector<vector<int>> dp(n, vector<int> (amount+1, 1e9));
        for(int j = 0; j <= amount; j++)
            if(j % coins[0] == 0)  // Base case
                dp[0][j] = j / coins[0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int notTake = dp[i-1][j], take = 1e9;
                if(j >= coins[i]) take = 1 + dp[i][j-coins[i]];
                dp[i][j] = min(take, notTake);
            }
        }
        return dp[n-1][amount];
    }*/

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<int> prev(amount+1, 1e9), cur(amount+1, 1e9);
 
        for (int j = 0; j <= amount; j++)  //Base case
            prev[j] = (j % coins[0] == 0) ? j / coins[0] : 1e9;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notTake = prev[j], take = 1e9;  //take n notTake
                if (j >= coins[i]) take = 1 + cur[j-coins[i]];
                cur[j] = min(take, notTake);
            }
            prev = cur;
        }

        return (prev[amount] != 1e9) ? prev[amount] : -1;
    }
};