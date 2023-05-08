#define mod 1000000007
class Solution {
public:
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,1},{0,-1}};
    int dfs(int n, int m, int maxMoves, int i, int j, vector<vector<vector<int>>>& dp) {

        // Count it -> out of boundary
        if (i<0 || i>=n || j<0 || j>=m) {
            return 1;
        }

        // All moves exhausted
        if (maxMoves==0) {
            return 0;
        }

        // Already calculated
        // dp[i][j][k] -> Standing at (i, j) with k more moves left
        if (dp[i][j][maxMoves] != -1) {
            return dp[i][j][maxMoves];
        }

        int cur = 0;
        for (auto [x, y] : direction) {
            int X = i + x;
            int Y = j + y;
            cur = (cur + dfs(n, m, maxMoves-1, X, Y, dp)) % mod;
        }
        return dp[i][j][maxMoves] = cur % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, 
            vector<vector<int>> (n, vector<int> (maxMove + 1, -1)));
        int totPaths = dfs(m, n, maxMove, startRow, startColumn, dp);
        return totPaths;
    }
};