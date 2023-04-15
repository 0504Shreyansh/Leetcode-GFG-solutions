class Solution {
public:
    int solve(vector<vector<int>>& piles, vector<vector<int>>& dp , int i , int k)
    {
        int n = piles.size();
        if(i==n || k==0) {
            return 0;
        }
        
        if(dp[i][k] != -1) {
            return dp[i][k];
        }
        
        int notTake = solve(piles, dp, i+1, k);
        int sum = 0;
        int take = 0;
        
        int m = piles[i].size();
        for(int j = 0; j < min(m, k) ; j++) {
            sum += piles[i][j];
            take = max(take, sum + solve(piles, dp, i+1, k-j-1));
        }

        return dp[i][k] = max(take, notTake);        
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(piles, dp, 0, k);
    }
};