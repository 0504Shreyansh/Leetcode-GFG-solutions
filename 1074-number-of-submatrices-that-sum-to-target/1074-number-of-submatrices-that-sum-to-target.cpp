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

// int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
//         int res = 0, m = A.size(), n = A[0].size();
//         for (int i = 0; i < m; i++)
//             for (int j = 1; j < n; j++)
//                 A[i][j] += A[i][j - 1];

//         unordered_map<int, int> counter;
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 counter = {{0,1}};
//                 int cur = 0;
//                 for (int k = 0; k < m; k++) {
//                     cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
//                     res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
//                     counter[cur]++;
//                 }
//             }
//         }
//         return res;
//     }