class Solution {
public:
    void bfs(vector<vector<char>> grid, vector<vector<int>> &visited, int i, int j, int n, int m) {
        queue<pair<int,int>> q;
        q.push({i,j});
        int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
        while(q.size()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int new_x = x+dx[i], new_y = y+dy[i];
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && !visited[new_x][new_y] && grid[new_x][new_y]=='1') {
                    q.push({new_x, new_y});
                    visited[new_x][new_y] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int numberOfIslands = 0;
        vector<vector<int>> visited(n,vector<int>(m));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    numberOfIslands++;
                    bfs(grid,visited,i,j,n,m);
                }
            }
        }
        
        return numberOfIslands;
    }
};