class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        vector<int> rows(n), cols(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    rows[i]++, cols[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    if (rows[i] == 1 && cols[j] == 1) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};