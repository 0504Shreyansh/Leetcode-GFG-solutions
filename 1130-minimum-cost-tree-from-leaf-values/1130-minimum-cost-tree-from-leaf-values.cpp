class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int ans = 0;
        while (A.size() > 1) {
            int n = A.size();
            int minProd = 404, idx = -1;
            for (int i = 1; i < n; i++) {
                if (minProd > A[i] * A[i - 1]) {
                    minProd = A[i] * A[i - 1];
                    idx = i;
                }
            }
            ans += minProd;
            A[idx] = max(A[idx - 1], A[idx]);
            A.erase(begin(A) + idx - 1);
        }
        return ans;
    }
};