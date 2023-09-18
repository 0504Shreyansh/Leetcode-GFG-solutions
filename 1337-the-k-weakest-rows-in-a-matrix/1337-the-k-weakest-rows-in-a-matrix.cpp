class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ones;
        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mat[i][mid] == 1) low = mid + 1;
                else high = mid - 1;
            }
            ones.push_back({low, i});
        }
        sort(begin(ones), end(ones));
        vector<int> ans;
        for (int i = 0; i < k; i++) 
            ans.push_back(ones[i][1]);
        return ans;
    }
};