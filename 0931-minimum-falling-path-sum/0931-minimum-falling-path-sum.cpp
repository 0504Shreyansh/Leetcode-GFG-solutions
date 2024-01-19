class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> prev(matrix[0]);
        for (int i = 1; i < n; i++) {
            vector<int> curr(m);
            for (int j = 0; j < m; j++) {
                curr[j] = matrix[i][j] + min({prev[j], (j != 0 ? prev[j - 1] : 10001), (j + 1 < m ? prev[j + 1] : 10001)});
            }
            prev = curr;
        }
        return *min_element(begin(prev), end(prev));
    }
};