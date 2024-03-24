class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int i = 0, n = A.size();
        while (i < n) {
            if (A[i] == i + 1) {
                i++;
            } else {
                if (A[i] == A[A[i] - 1]) {
                    return A[i];
                }
                swap(A[i], A[A[i] - 1]);
            }
        }
        return 0; 
    }
};