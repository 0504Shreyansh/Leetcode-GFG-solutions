class Solution {
public:
    bool isSafe(int i, int j, int n, int m) {
        return (i>=0 && i<n && j>=0 && j<m); 
    }

    vector<vector<int>>spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int dist = 1;
        while(ans.size() < rows * cols) {
            int moveRight = dist, moveDown = dist, moveLeft = dist+1, moveUp = dist+1;
            // Move dist distance right 
            while(moveRight--) {
                if(isSafe(rStart, cStart, rows, cols)) {
                    ans.push_back({rStart, cStart});
                }
                cStart++;
            }
            // Move dist distance down 
            while(moveDown--) {
                if(isSafe(rStart, cStart, rows, cols)) {
                    ans.push_back({rStart, cStart});
                }
                rStart++;
            }
            // Move (dist+1) distance left to cover up
            while(moveLeft--) {
                if(isSafe(rStart, cStart, rows, cols)) {
                    ans.push_back({rStart, cStart});
                }
                cStart--;
            }
            // Move (dist+1) distance up to cover up
            while(moveUp--) {
                if(isSafe(rStart, cStart, rows, cols)) {
                    ans.push_back({rStart, cStart});
                }
                rStart--;
            }
            // Increase original distance by 2
            dist += 2;
        }
        return ans;
    }
};