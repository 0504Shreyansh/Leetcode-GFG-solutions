class Solution {
private:
    double dijkstra(string u, string v, unordered_map<string, vector<pair<string, double>>>& graph, unordered_map<string, double> dist) {
        if (graph.find(u) == graph.end() || graph.find(v) == graph.end()) {
            return -1.0;
        }
        dist[u] = 1.0;
        priority_queue<pair<double, string>> q;
        q.push({-dist[u], u});
        unordered_map<string, int> vis;
        while (q.size()) {
            auto cur = q.top();
            q.pop();
            double wt = -cur.first;
            string a = cur.second;
            if (vis[a]) continue;
            vis[a] = 1;
            for (auto &nbr : graph[a]) {
                string b = nbr.first;
                double w = nbr.second;
                dist[b] = min(dist[b], dist[a] * w);
                q.push({-dist[b], b});
            }
        }
        if (dist[v] < 1e-30) return 1.0;
        return dist[v] == 2e9 * 1.0 ? -1 : dist[v];
    }
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& w, vector<vector<string>>& queries) {
        int n = e.size();
        unordered_map<string, vector<pair<string, double>>> graph;
        unordered_map<string, double> dist;
        for (int i = 0; i < n; i++) {
            string u = e[i][0];
            string v = e[i][1];
            double wt = w[i];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, 1.0/wt});
            dist[u] = dist[v] = 2e9 * 1.0;
        }
        vector<double> res;
        for (auto &q : queries) {
            string source = q[0];
            string dest = q[1];
            double wt = dijkstra(source, dest, graph, dist);
            res.push_back(wt);
        }
        return res;
    }
};