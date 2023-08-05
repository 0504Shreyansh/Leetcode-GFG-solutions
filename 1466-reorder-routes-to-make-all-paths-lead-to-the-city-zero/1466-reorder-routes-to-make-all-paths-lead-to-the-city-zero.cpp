class Solution {
private:
    int ans = 0;
    void dfs(int u, vector<pair<int, int>> adj[], vector<int>& vis) {
        vis[u] = 1;
        for (auto &[v, num] : adj[u]) {
            if (!vis[v]) {
                if (num == 0) ans++;
                dfs(v, adj, vis);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& C) {
        vector<pair<int, int>> adj[n];
        for (auto &it : C) {
            adj[it[0]].push_back({it[1], 0});
            adj[it[1]].push_back({it[0], 1});
        }
        vector<int> vis(n);
        dfs(0, adj, vis);
        return ans;
    }
};