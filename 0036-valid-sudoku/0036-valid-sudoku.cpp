class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<set<int>> row(9), col(9), blocks(9);
        
        for (int r = 0; r < 9; r++) 
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                    continue;
                
                int cur = board[r][c] - '0';
                
                if (row[r].count(cur) || col[c].count(cur) || blocks[(r/3)*3+c/3].count(cur))
                    return false;
                
                row[r].insert(cur);
                col[c].insert(cur);
                blocks[(r/3)*3+c/3].insert(cur);
            }
        }
            
        return true;
    }
};