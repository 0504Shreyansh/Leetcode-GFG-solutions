class Solution {
private:
    int dirs[5] = {0, -1, 0, 1, 0};
    bool isValid(int x, int y, vector<vector<int>>& grid) {
        return (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] == 0);
    }
    void dfs(int i, int j, vector<vector<int>>& newGrid, vector<vector<int>>& vis) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (isValid(x, y, newGrid) && !vis[x][y]) {
                dfs(x, y, newGrid, vis);
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size() * 3;
        int m = grid[0].size() * 3;
        vector<vector<int>> newGrid(n, vector<int> (m));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '/') {
                    newGrid[i * 3][j * 3 + 2] = 1;
                    newGrid[i * 3 + 1][j * 3 + 1] = 1;
                    newGrid[i * 3 + 2][j * 3] = 1;
                }
                if (grid[i][j] == '\\') {
                    newGrid[i * 3][j * 3] = 1;
                    newGrid[i * 3 + 1][j * 3 + 1] = 1;
                    newGrid[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        int ans = 0;
        vector<vector<int>> vis(n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && !newGrid[i][j]) {
                    ans++;
                    dfs(i, j, newGrid, vis);
                }
            }
        }
        return ans;
    }
};