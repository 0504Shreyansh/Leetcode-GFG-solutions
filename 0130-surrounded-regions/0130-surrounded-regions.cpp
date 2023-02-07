class Solution {
private:
    void dfs(vector<vector<char>> &board, vector<vector<int>> &visited, int sr, int sc) {
        visited[sr][sc] = 1;
        int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
        int n = board.size(), m = board[0].size();
        
        for (int index = 0; index < 4; index++) {
            int new_row = sr + dx[index], new_col = sc + dy[index];
            if (new_row>=0 && new_row<n && new_col>=0 && new_col<m && !visited[new_row][new_col] && board[new_row][new_col]=='O')
                dfs(board, visited, new_row, new_col);
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int> (m));
        
        //Visit all the boundaries and its adjacent O's
        for (int row = 0; row < n; row++) {
            if(!visited[row][0] && board[row][0]=='O')
                dfs(board, visited, row, 0);
            if(!visited[row][m-1] && board[row][m-1]=='O')
                dfs(board, visited, row, m-1);
        }
        
        for (int col = 0; col < m; col++) {
            if(!visited[0][col] && board[0][col]=='O')
                dfs(board, visited, 0, col);
            if(!visited[n-1][col] && board[n-1][col]=='O')
                dfs(board, visited, n-1, col);
        }
        
        //Mark the insided O's to X's
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if(!visited[row][col] && board[row][col]=='O')
                    board[row][col] = 'X';
            }
        }
        
    }
};