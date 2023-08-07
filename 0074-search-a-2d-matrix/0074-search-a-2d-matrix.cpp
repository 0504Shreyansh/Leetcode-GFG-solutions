class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n - 1;
        int row = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                row = mid;
                low = mid + 1;
            }
        }

        low = 0, high = m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};