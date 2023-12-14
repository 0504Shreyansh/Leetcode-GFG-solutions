class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> rowOnes(n), colOnes(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    rowOnes[i]++, colOnes[j]++;
                }
            } 
        } 
        vector<vector<int>> ans(n, vector<int> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = 2 * (rowOnes[i] + colOnes[j]) - (n + m);
            }
        } 
        return ans;
    }
};