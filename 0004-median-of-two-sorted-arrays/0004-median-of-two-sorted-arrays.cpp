class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        if (n > m) return findMedianSortedArrays(B, A);
        int left = (n + m + 1) / 2; 
        int low = 0, high = n;
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = (n + m + 1) / 2 - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n) r1 = A[mid1];
            if (mid2 < m) r2 = B[mid2];
            if (mid1 - 1 >= 0) l1 = A[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = B[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 == 1) return max(l1, l2);
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0; 
    }
};