class Solution {
public:
    vector<pair<int,int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>>& grid, int cnt) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[i][j] == 2) {
            return (cnt == n * m - 1) ? 1 : 0;
        }
        int ans = 0;
        grid[i][j] = -1;
        for(auto [dx, dy] : direction) {
            int X = i + dx;
            int Y = j + dy;
            if(X >= 0 && X < n && Y >= 0 && Y < m && grid[X][Y] != -1) {
                ans += dfs(X, Y, grid, cnt + 1);
            }
        } 
        grid[i][j] = 0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr, sc;
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    sr = i, sc = j;
                }
                else if(grid[i][j] == -1) {
                    cnt++;
                }
            }
        }
        
        return dfs(sr, sc, grid, cnt);
    }
};