class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<int, int> rows, cols, posDiag, negDiag;
        map<pair<int, int>, int> present;
        for (auto &lamp : lamps) {
            int row = lamp[0], col = lamp[1];
            if (present.find({row, col}) != present.end()) continue;
            rows[row]++, cols[col]++, posDiag[col - row]++, negDiag[row + col]++;
            present[{row, col}] = 1;
        }
        vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, 
                                    {0, -1}, {0, 0}, {0, 1}, 
                                    {1, -1}, {1, 0}, {1, 1}}; 
        vector<int> ans;
        for (auto &q : queries) {
            int row = q[0], col = q[1];
            if (rows[row] > 0 || cols[col] > 0 || posDiag[col - row] > 0 || negDiag[row + col] > 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
            for (int k = 0; k < 8; k++) {
                int x = row + dirs[k][0], y = col + dirs[k][1];
                if (present.count({x, y})) {
                    present.erase({x, y});
                    if (--rows[x] == 0) rows.erase(x);
                    if (--cols[y] == 0) cols.erase(y);
                    if (--posDiag[y - x] == 0) posDiag.erase(y - x);
                    if (--negDiag[x + y] == 0) negDiag.erase(x + y);
                }
            }
        }
        return ans;
    }
};