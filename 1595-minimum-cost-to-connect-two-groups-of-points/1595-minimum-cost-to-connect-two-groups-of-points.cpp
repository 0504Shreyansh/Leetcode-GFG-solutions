class Solution {
private:
    int solve(int i, int j, int mask, vector<vector<int>>& cost,
              vector<vector<vector<int>>>& dp) {
        if(i >= cost.size()) {
            if(mask == (1 << cost[0].size()) - 1) {
                return 0;
            }
            return 1e5;
        }
        if(dp[i][j][mask] != -1) {
            return dp[i][j][mask];
        }
        int takeAndStayInRow = 1e5, skipValueAndStayInRow = 1e5;
        if(j + 1 != cost[i].size()) 
            skipValueAndStayInRow = solve(i, j + 1, mask, cost, dp);

        if(j + 1 != cost[i].size()) 
            takeAndStayInRow = cost[i][j] + solve(i, j + 1, mask | (1 << j), cost, dp);

        int takeAndSkipRow = cost[i][j] + solve(i + 1, 0, mask | (1 << j), cost, dp);
        return dp[i][j][mask] = min({skipValueAndStayInRow, 
                                     takeAndSkipRow, takeAndStayInRow});
    }

public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        vector<vector<vector<int>>> dp(cost.size(), 
            vector<vector<int>> (cost[0].size(), 
                vector<int> ((1 << cost[0].size()), -1)));
        return solve(0, 0, 0, cost, dp);
    }
};