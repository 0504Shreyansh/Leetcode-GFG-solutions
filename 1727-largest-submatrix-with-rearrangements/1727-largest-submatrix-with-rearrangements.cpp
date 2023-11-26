class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> heights(matrix);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (heights[i][j] == 1) {
                    heights[i][j] += heights[i - 1][j]; 
                } 
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            sort(begin(heights[i]), end(heights[i]));
            for (int j = m - 1; j >= 0; j--) {
                res = max(res, heights[i][j] * (m - j));
            }
        }
        return res;
    }
};