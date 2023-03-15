class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == 0)
                    matrix[i][j] = -111111111;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == -111111111) {
                    int y = 0;
                    while (y < matrix[i].size()) {
                        if (matrix[i][y] != -111111111)
                            matrix[i][y] = 0;
                        y++;
                    }
                    int x = 0;
                    while (x < matrix.size()) {
                        if (matrix[x][j] != -111111111)
                            matrix[x][j] = 0;
                        x++;
                    }
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == -111111111)
                    matrix[i][j] = 0;
        
    }
};