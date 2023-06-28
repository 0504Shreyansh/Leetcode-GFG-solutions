class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, 
    vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> graph[n];
        for(int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        pq.push({dist[start], start});
        while(pq.size()) {
            int node = pq.top().second;
            pq.pop();
            for(auto &neighbour : graph[node]) {
                int adjNode = neighbour.first;
                double prob = neighbour.second;
                if(dist[adjNode] < dist[node] * prob) {
                    dist[adjNode] = dist[node] * prob;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist[end];
    }
};