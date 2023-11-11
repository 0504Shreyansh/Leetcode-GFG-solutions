class Graph {
private:
    vector<pair<int, int>> G[101];
public:
    Graph(int n, vector<vector<int>>& edges) {
        for (auto &edge : edges) {
            G[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        G[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(101, 1e9);
        dist[node1] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, node1});
        while (pq.size()) {
            int u = pq.top().second;
            pq.pop();
            if (u == node2) return dist[u];
            for (auto &[v, w] : G[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({-dist[v], v});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */