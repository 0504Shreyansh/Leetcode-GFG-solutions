class Solution {
private:
    vector<vector<string>> ans;
    bool check(int row, int col, int n, vector<string>& board) {
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') return false;
        }
        int i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i--, j--;
        }
        i = row, j = col;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i++, j--;
        }
        return true;
    }
    void solve(int col, int n, vector<string>& board) {
        if (col == n) {
            ans.push_back(board);
            return ;
        }
        for (int row = 0; row < n; row++) {
            if (check(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col + 1, n, board);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string r(n, '.');
        vector<string> board(n, r);
        solve(0, n, board);
        return ans;
    }
};