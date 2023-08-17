class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int dirs[] = {0, -1, 0, 1, 0};
        queue<pair<int, int>> Q;
        vector<vector<int>> ans(n, vector<int> (m, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    Q.push({i, j});
                }
            }
        }
        int dist = 1;
        while (Q.size()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                auto cur = Q.front();
                Q.pop();
                int x = cur.first;
                int y = cur.second;
                for (int k = 0; k < 4; k++) {
                    int X = x + dirs[k], Y = y + dirs[k + 1];
                    if (X >= 0 && X < n && Y >= 0 && Y < m && mat[X][Y] == 1 && ans[X][Y] == 1e9) {
                        Q.push({X, Y});
                        ans[X][Y] = dist;
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};