class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        vector<int> ans;
        int top = 0, bottom = N - 1;
        int left = 0, right = M - 1;
        while (top <= bottom && left <= right) {
            // First row
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            // Last col
            for (int i = top; i <= bottom; i++) 
                ans.push_back(matrix[i][right]);
            right--;

            // Last row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) 
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            // First col
            if (left <= right) {
                for (int i = bottom; i >= top; i--) 
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};