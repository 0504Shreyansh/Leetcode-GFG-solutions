class Solution {
private:
    double dijkstra(string &src, string &dest, map<string, vector<pair<string, double>>>& G) {
        if (!G.count(src) || !G.count(dest)) return -1.0;
        if (src == dest) return (G.count(src) != 0) ? 1.0 : -1.0;
        map<string, double> dist;
        dist[src] = 1;
        priority_queue<pair<double, string>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            string u = pq.top().second;
            pq.pop();
            if (u == dest) return dist[dest];
            for (auto &[v, w] : G[u]) {
                if (!dist.count(v)) {
                    dist[v] = dist[u] * w;
                    pq.push({-dist[v], v});
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        map<string, vector<pair<string, double>>> G;
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            G[u].push_back({v, w});
            G[v].push_back({u, 1.0 / w});
        }
        vector<double> ans;
        for (auto &q : queries) {
            string src = q[0], dest = q[1];
            double dist = dijkstra(src, dest, G);
            ans.push_back(dist);
        }
        return ans;
    }
};