class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> G[n];
        vector<vector<int>> graph(n, vector<int> (n));
        for (auto &it : edges) {
            G[it[0] - 1].push_back(it[1] - 1);
            G[it[1] - 1].push_back(it[0] - 1);
            graph[it[0] - 1][it[1] - 1] = 1;
            graph[it[1] - 1][it[0] - 1] = 1;
        }
        int minDeg = INT_MAX;
        for (int u = 0; u < n; u++) {
            int size = G[u].size();
            for (int i = 0; i < size; i++) {
                int v = G[u][i];
                for (int j = i + 1; j < size; j++) {
                    int w = G[u][j];
                    if (graph[v][w] == 1) {
                        minDeg = min({minDeg, (int)G[u].size() + (int)G[v].size() + (int)G[w].size() - 6});
                    }
                }
            }
        }
        if (minDeg == INT_MAX) return -1;
        return minDeg;
    }
};