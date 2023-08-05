class Solution {
private:
    void dfs(int u, vector<int> adj[], vector<int>& vis) {
        vis[u] = 1;
        for (auto &v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& C) {
        vector<int> adj[n];
        for (auto &it : C) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int comp = 0;
        vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                comp++;
                dfs(i, adj, vis);
            }
        }
        return (C.size() >= n - 1) ? comp - 1 : -1;
    }
};