class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int n = A.size(), i = 0;
        while (i < n) {
            if (A[i] != i + 1) {
                int pos = A[i] - 1;
                if (A[i] != A[pos]) {
                    swap(A[i], A[pos]);
                } else {
                    return A[i];
                }
            } else {
                i++;
            }
        }
        return 0;
    }
};