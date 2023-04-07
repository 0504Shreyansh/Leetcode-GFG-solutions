class Solution {
public:
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int &cnt, int i, int j, vector<vector<int>>& grid, bool toCount) {
        grid[i][j] = 0;
        if(toCount==true)
            cnt++;
        int N = grid.size(), M = grid[0].size();
        for(auto [x, y] : direction) {
            int X = i + x, Y = j + y;
            if(X>=0 && X<N && Y>=0 && Y<M && grid[X][Y]==1) {
                dfs(cnt, X, Y, grid, toCount);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        int cnt = 0;
        
        for(int i = 0; i < N; i++) {
            if(grid[i][0]==1)
                dfs(cnt, i, 0, grid, 0);
            if(grid[i][M-1]==1)
                dfs(cnt, i, M-1, grid, 0);
        }
        
        for(int j = 0; j < M; j++) {
            if(grid[0][j]==1)
                dfs(cnt, 0, j, grid, 0);
            if(grid[N-1][j]==1)
                dfs(cnt, N-1, j, grid, 0);
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j]==1) {
                    dfs(cnt, i, j, grid, true);
                }
            }
        }
        return cnt;
    }
};