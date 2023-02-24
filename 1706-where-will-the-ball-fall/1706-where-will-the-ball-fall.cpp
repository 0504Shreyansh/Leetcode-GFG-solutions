class Solution {
public:
    vector<int> ans;
    void bfs(int row, int col, vector<vector<int>>& grid) {
        queue<pair<int,int>> q({{row, col}});
        int n = grid.size(), m = grid[0].size(), val = -1;
        while(q.size()) {
            auto cur = q.front();
            q.pop();
            int curRow = cur.first, curCol = cur.second;
            if(curRow==n) {
                val = curCol; break;
            }
            if(grid[curRow][curCol]==1) {
                if(curCol+1<m && grid[curRow][curCol+1]!=-1)         
                    q.push({curRow+1, curCol+1});
                else 
                    break;
            }
            else {
                if(curCol-1>=0 && grid[curRow][curCol-1]!=1)
                    q.push({curRow+1, curCol-1});
                else 
                    break;
            }
        }
        ans.push_back(val);
    }
    vector<int> findBall(vector<vector<int>> &grid) {

        int m = grid[0].size();
        for (int j = 0; j < m; j++) 
            bfs(0, j, grid);
        return ans;
    }
};