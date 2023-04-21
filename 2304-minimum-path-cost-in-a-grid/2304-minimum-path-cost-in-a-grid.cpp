class Solution {
public:
    int dp[51][51];
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        if(i==grid.size()-1) {
            return grid[i][j];
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int cur = INT_MAX;
        for(int k = 0; k < grid[i].size(); k++) {
            int curMove = grid[i][j] + moveCost[grid[i][j]][k] + solve(i+1, k, grid, moveCost);
            cur = min(cur, curMove);
        }
        return dp[i][j] = cur;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int res = INT_MAX;
        memset(dp, -1, sizeof dp);
        for(int j = 0; j < grid[0].size(); j++) {
            res = min(res, solve(0, j, grid, moveCost));
        }
        return res;
    }
};