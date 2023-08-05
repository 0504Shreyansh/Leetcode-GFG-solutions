class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> graph[n];
        for (auto &it : redEdges) {
            graph[it[0]].push_back({it[1], 1});
        }
        for (auto &it : blueEdges) {
            graph[it[0]].push_back({it[1], 2});
        }
        vector<vector<int>> dist(n, vector<int> (3, 1e9));
        queue<vector<int>> q({{0, 0, 0}});
        dist[0][1] = dist[0][2] = 0;
        while (q.size()) {
            int u = q.front()[0];
            int prev_color = q.front()[1];
            int steps = q.front()[2];
            q.pop();
            for (auto &[v, color] : graph[u]) {
                if (color == prev_color) continue;
                if (dist[v][color] == 1e9) {
                    dist[v][color] = steps + 1;
                    q.push({v, color, steps + 1});
                }
            }
        }
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (dist[i][1] != 1e9 || dist[i][2] != 1e9) {
                ans[i] = min(dist[i][1], dist[i][2]);
            }
        }
        return ans;
    }
};