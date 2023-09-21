class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        if (n > m) return findMedianSortedArrays(B, A);
        int low = 0, high = n;
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (n + m + 1) / 2 - cut1;
            int l1 = (cut1 - 1 >= 0) ? A[cut1 - 1] : INT_MIN;
            int l2 = (cut2 - 1 >= 0) ? B[cut2 - 1] : INT_MIN;
            int r1 = (cut1 < n) ? A[cut1] : INT_MAX;
            int r2 = (cut2 < m) ? B[cut2] : INT_MAX;
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 == 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
        }
        return 0.0;
    }
};