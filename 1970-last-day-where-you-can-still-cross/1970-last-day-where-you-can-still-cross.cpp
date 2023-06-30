class Solution {
private:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(int i, int j, vector<vector<int>>& grid, int row, int col) {
        if(i == row - 1) return true;
        grid[i][j] = -1;
        bool ans = false;
        for(auto [dx, dy] : dir) {
            int I = i + dx;
            int J = j + dy;
            if(I >= 0 && I < row && J >= 0 && J < col && grid[I][J] == 0) {
                ans |= dfs(I, J, grid, row, col);
            }
        }
        return ans;
    }

    bool isPossible(int mid, vector<vector<int>>& cells, int row, int col) {
        vector<vector<int>> grid(row, vector<int> (col));
        // Block all the required cells
        for(int i = 0; i <= mid; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
    
        // Check if it can be crossed
        for(int j = 0; j < col; j++) {
            if(grid[0][j] == 0 && dfs(0, j, grid, row, col)) {
                return true;
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0;
        int high = cells.size() - 1;
        int res = 0;
        
        // Apply binary search for the cells to check we can cross
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(mid, cells, row, col)) {
                res = mid;
                low = mid + 1;  // if we can, go for further more days
            } else {
                high = mid - 1; // else go backwards by some days
            }
        }
        return res + 1;
    }
};