class Solution {
public:
    int recSol(int i, int j1, int j2, vector<vector<int>>& grid) {
        // Not a valid cell
        if(j1 < 0 | j2 < 0 | j1 >= grid[0].size() | j2 >= grid[0].size())
            return -1e9;
        // Check if the cells are same, then return only one time.
        if(i == grid.size() - 1) {
            if(j1 == j2) 
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        
        // Consider all possible cells from the two cur cells
        int cur = 0;
        for(int dy1 = -1; dy1 <= 1; dy1++) {
            for(int dy2 = -1; dy2 <= 1; dy2++) {
                int X = i + 1;
                int Y1 = j1 + dy1;
                int Y2 = j2 + dy2;
                if(j1 == j2)
                    cur = max(cur, grid[i][j1] + recSol(X, Y1, Y2, grid));
                else 
                    cur = max(cur, grid[i][j1] + grid[i][j2] + recSol(X, Y1, Y2, grid)); 
            }
        }
        return cur;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2) {
                    dp[n-1][j1][j2] = grid[n-1][j1];
                }
                else {
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }
        
        for(int i = n-2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    
                    int cur = 0;
                    
                    for(int dy1 = -1; dy1 <= 1; dy1++) {
                        for(int dy2 = -1; dy2 <= 1; dy2++) {
                            int Y1 = j1 + dy1;
                            int Y2 = j2 + dy2;
                            int value = 0;
                            if(j1 == j2) 
                                value += grid[i][j1];
                            else 
                                value += grid[i][j1] + grid[i][j2];
                            if(Y1>=0 && Y1<m && Y2>=0 && Y2<m)
                                value += dp[i+1][Y1][Y2];
                            cur = max(cur, value);
                        }
                    }
                    
                    dp[i][j1][j2] = cur;
                    
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};