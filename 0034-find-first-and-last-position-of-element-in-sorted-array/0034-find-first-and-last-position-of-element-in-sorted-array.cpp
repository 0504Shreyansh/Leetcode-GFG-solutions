class Solution {
public:
    vector<int> searchRange(vector<int>& A, int k) {
        int n = A.size();
        vector<int> ans(2, -1);
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == k) {
                ans[0] = mid;
            } 
            if (A[mid] < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == k) {
                ans[1] = mid;
            } 
            if (A[mid] <= k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};