class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> visit(n, vector<int> (m));
        int dirs[5] = {0, -1, 0, 1, 0};
        while (pq.size()) {
            auto C = pq.top();
            pq.pop();
            int d = -C.first, x = C.second.first, y = C.second.second;
            if (visit[x][y]) continue;
            visit[x][y] = 1;
            if (x == n - 1 && y == m - 1) return d;
            for (int k = 0; k < 4; k++) {
                int X = x + dirs[k], Y = y + dirs[k + 1];
                if (X >= 0 && X < n && Y >= 0 && Y < m) {
                    pq.push({-(d + grid[X][Y]), {X, Y}});
                }
            }
        }
        return 0;
    }
};