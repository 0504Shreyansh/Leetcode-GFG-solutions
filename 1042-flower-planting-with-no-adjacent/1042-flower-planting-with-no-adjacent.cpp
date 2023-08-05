class Solution {
private:
    bool isSafe(int u, int c, vector<int> adj[], vector<int>& color) {
        for (auto &v : adj[u]) {
            if (color[v] == c) {
                return false;
            } 
        }
        return true;
    }
    void dfs(int u, int c, vector<int> adj[], vector<int>& color) {
        color[u] = c;
        for (auto &v : adj[u]) {
            if (color[v] == -1) {
                for (int k = 1; k <= 4; k++) {
                    if (isSafe(v, k, adj, color)) {
                        dfs(v, k, adj, color);
                    }
                }
            } 
        }
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n];
        for (auto &it : paths) {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }
        vector<int> color(n, -1);
        for (int u = 0; u < n; u++) {
            if (color[u] == -1) {
                dfs(u, 1, adj, color);
            }
        }
        return color;
    }
};