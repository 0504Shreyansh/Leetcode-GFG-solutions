class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        vector<int> A(arr);
        sort(begin(A), end(A));
        int prev = 1, n = A.size();
        for (int i = 1; i < n; i++) {
            if (prev == A[i] || prev == A[i] + 1) {
                prev = A[i];
            } else {
                prev++;
            }
        }
        return prev;
    }
};