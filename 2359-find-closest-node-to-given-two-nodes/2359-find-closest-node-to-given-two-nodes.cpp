class Solution {
private:
    vector<int> bfs(int node, vector<int> adj[], int n) {
        vector<int> dist(n, 1e9);
        dist[node] = 0;
        int steps = 0;
        queue<int> Q({node});
        while (Q.size()) {
            int size = Q.size();
            while (size--) {
                int u = Q.front();
                Q.pop();
                for (auto &v : adj[u]) {
                    if (dist[v] > dist[u] + 1) {
                        dist[v] = dist[u] + 1;
                        Q.push(v);
                    }
                }
            }
            steps++;
        }
        return dist;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        vector<int> dist1 = bfs(node1, adj, n);
        vector<int> dist2 = bfs(node2, adj, n);
        int d = 1e9;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (d > max(dist1[i], dist2[i])) {
                d = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
    }
};