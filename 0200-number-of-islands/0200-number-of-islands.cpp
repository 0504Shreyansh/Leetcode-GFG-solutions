class Solution {
private:
    int dirs[5] = {0, -1, 0, 1, 0};
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& visit) {
        visit[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int X = i + dirs[k], Y = j + dirs[k + 1];
            if (X >= 0 && X < n && Y >= 0 && Y < m && grid[X][Y] == '1' && !visit[X][Y]) {
                dfs(X, Y, n, m, grid, visit);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), islands = 0;
        vector<vector<int>> visit(n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visit[i][j]) {
                    islands++;
                    dfs(i, j, n, m, grid, visit);
                }
            }
        }
        return islands;
    }
};