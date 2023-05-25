#define mod 1000000007
class Solution {
public:
    vector<pair<int,int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        } 
        int N = grid.size();
        int M = grid[0].size();
        vis[i][j] = 1;
        int curr = 1;
        for(auto [dx, dy] : direction) {
            int newX = i + dx;
            int newY = j + dy;
            if(newX >= 0 && newX < N && newY >= 0 && newY < M 
               && !vis[newX][newY] && grid[i][j] < grid[newX][newY]) {
                curr = (curr + dfs(newX, newY, grid, vis, dp)) % mod;
            }
        }
        vis[i][j] = 0;
        return dp[i][j] = curr;
    }
    int countPaths(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(N, vector<int> (M, 0));
        vector<vector<int>> dp(N, vector<int> (M, -1));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                ans = (ans + dfs(i, j, grid, vis, dp)) % mod;
            }
        }
        return ans;
    }
};