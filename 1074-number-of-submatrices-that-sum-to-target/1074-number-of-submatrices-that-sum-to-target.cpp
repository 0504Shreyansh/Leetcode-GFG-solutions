class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0, n = matrix.size(), m = matrix[0].size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        } 
        
        for (int j1 = 0; j1 < m; ++j1) {
            for (int j2 = j1; j2 < m; ++j2) {
                map<int, int> mp = {{0, 1}};
                sum = 0;
                for (int i = 0; i < n; ++i) {
                    sum += matrix[i][j2] - (j1 ? matrix[i][j1 - 1] : 0);
                    ans += mp[sum - target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};