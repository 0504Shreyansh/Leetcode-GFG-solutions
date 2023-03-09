class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adjList[n];
        vector<double> dist(n, 0);
            
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        
        priority_queue<pair<double,int>> pq;
        pq.push({1, start});
        dist[start] = 1;
        
        //Max-heap priority_queue + dijkstra
        while(pq.size()) {
            int u = pq.top().second;
            pq.pop();
            for(auto x : adjList[u]) {
                int v = x.first;
                double w = x.second;
                if(dist[v] < dist[u] * w) {
                    dist[v] = dist[u] * w;
                    pq.push({dist[v], v});
                }  
            }
        }
        
        return dist[end];
    }
};