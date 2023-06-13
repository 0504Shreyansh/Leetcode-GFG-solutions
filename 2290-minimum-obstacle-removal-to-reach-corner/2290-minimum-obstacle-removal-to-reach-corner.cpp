class Solution {
public:
    vector<pair<int,int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vis[0][0] = 1;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int obsRemoved = -curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            if(i == n - 1 && j == m - 1) {
                return obsRemoved;
            }
            // cout << i << ' ' << j << ' ' << obsRemoved << endl;
            for(auto [x, y] : direction) {
                int X = i + x;
                int Y = j + y;
                if(X >= 0 && X < n && Y >= 0 && Y < m && !vis[X][Y]) {
                    vis[X][Y] = 1;
                    pq.push({-(obsRemoved + (grid[X][Y] == 1)), {X, Y}});
                }
            }
        }
        return -1;
    }
};