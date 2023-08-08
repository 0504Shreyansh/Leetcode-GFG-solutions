class Solution {
public:
    int search(vector<int>& A, int target) {
        int low = 0;
        int high = A.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target) return mid;
            if (A[low] <= A[mid]) {
                if (A[low] <= target && target <= A[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (A[mid] <= target && target <= A[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};