class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int counter = 1;
        while (top <= bottom && left <= right) {
            // First row
            for (int i = left; i <= right; i++)
                ans[top][i] = counter++;
            top++;

            // Last col
            for (int i = top; i <= bottom; i++) 
                ans[i][right] = counter++;
            right--;

            // Last row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) 
                    ans[bottom][i] = counter++;
                bottom--;
            }

            // First col
            if (left <= right) {
                for (int i = bottom; i >= top; i--) 
                    ans[i][left] = counter++;
                left++;
            }
        }
        return ans;
    }
};