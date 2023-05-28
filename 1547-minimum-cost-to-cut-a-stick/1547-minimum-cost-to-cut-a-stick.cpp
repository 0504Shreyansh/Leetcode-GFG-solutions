class Solution {
public:
    int solve(int n, int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(i > j) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int minCost = 1e9;
        for(int k = i; k <= j; k++) {
            int curCost = (cuts[j + 1] - cuts[i - 1]) + solve(n, i, k - 1, cuts, dp) + solve(n, k + 1, j, cuts, dp);
            minCost = min(minCost, curCost);
        } 
        return dp[i][j] = minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts),end(cuts));
        vector<vector<int>> dp(c + 2, 
                vector<int> (c + 2, -1));
        return solve(n, 1, c, cuts, dp);
    }
};