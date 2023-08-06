class Solution {
private:
    void dfs(int node, vector<pair<int, int>> adj[], vector<int>& vis) {
        vis[node] = 1;
        for (auto &[adjNode, wt] : adj[node]) {
            if (!vis[adjNode]) {
                dfs(adjNode, adj, vis);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto &it : roads) {
            adj[it[0]-1].push_back({it[1]-1, it[2]});
            adj[it[1]-1].push_back({it[0]-1, it[2]});
        }
        vector<int> vis(n);
        dfs(0, adj, vis);
        for (auto &it : vis) cout << it << ' '; cout << endl;
        int ans = 1e5;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) {
                for (auto &it : adj[i]) {
                    if (vis[it.first] == 1) {
                        ans = min(ans, it.second);
                    }
                }
            }
        }
        return ans;
    }
};