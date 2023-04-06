class Solution {
public:
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 1;
        int N = grid.size(), M = grid[0].size();
        for(auto [x, y] : direction) {
            int X = i + x, Y = j + y;
            if(X>=0 && Y>=0 && X<N && Y<M && grid[X][Y]==0) {
                dfs(X, Y, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        int N = grid.size(), M = grid[0].size();
        
        for(int i = 0; i < N; i++) {
            if(grid[i][0]==0)
                dfs(i, 0, grid);
            if(grid[i][M-1]==0)
                dfs(i, M-1, grid);
        }
        
        for(int j = 0; j < M; j++) {
            if(grid[0][j]==0)
                dfs(0, j, grid);
            if(grid[N-1][j]==0)
                dfs(N-1, j, grid);
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j]==0) {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return cnt;
    }
};