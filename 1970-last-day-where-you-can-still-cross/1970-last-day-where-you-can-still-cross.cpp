class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(int i, int j, vector<vector<int>>& grid, int row, int col) {
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != 0) return false;
        if(i == row - 1) return true;
        grid[i][j] = -1;
        bool ans = false;
        for(auto v : dir) {
            int I = i + v.first;
            int J = j + v.second;
            if(dfs(I, J, grid, row, col)) return true;
        }
        return ans;
    }

    bool isPossible(int mid, vector<vector<int>>& cells, int row, int col) {
        vector<vector<int>> grid(row, vector<int> (col));
        for(int i = 0; i <= mid; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        for(int j = 0; j < col; j++) {
            if(grid[0][j] == 0 && dfs(0, j, grid, row, col)) {
                return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0;
        int high = cells.size() - 1;
        int res = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(mid, cells, row, col)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res + 1;
    }
};