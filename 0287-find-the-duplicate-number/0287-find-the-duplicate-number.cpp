class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int i = 0, n = A.size();
        while (i < n) {
            if (A[i] != i + 1) {
                int pos = A[i] - 1;
                if (pos >= 0 && pos < n && A[i] != A[pos]) {
                    swap(A[i], A[pos]);
                } else {
                    return A[pos];
                }
            } else {
                i++;
            }
        }
        return n;
    }
};