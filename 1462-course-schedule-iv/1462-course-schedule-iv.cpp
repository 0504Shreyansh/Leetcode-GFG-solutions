class Solution {
private:
    bool bfs(int start, int dest, vector<int> adj[], int n) {
        vector<int> vis(n);
        vis[start] = 1;
        queue<int> q({start});
        while (q.size()) {
            int u = q.front();
            q.pop();
            if (u == dest) return 1;
            for (auto &v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return 0;
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> adj[n];
        for (auto &it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        vector<bool> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0], v = queries[i][1];
            bool res = bfs(u, v, adj, n);
            if (res) ans[i] = 1;
        }
        return ans;
    }
};