class Solution {
public:
    vector<int> dijkstra(vector<pair<int,int>> adj[], int n, int i) {
        vector<int> dist(n, 1e9);
        dist[i] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, i});
        while(pq.size()) {
            int node = pq.top().second;
            pq.pop();
            for(auto nbr : adj[node]) {
                if(dist[nbr.first] > dist[node] + nbr.second) {
                    dist[nbr.first] = dist[node] + nbr.second;
                    pq.push({dist[nbr.first], nbr.first});
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>> adj[n];
        for(auto e: edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        int cityNumber = -1, cityCount = n;
        for(int i = 0; i < n; i++) {
            vector<int> cur = dijkstra(adj, n, i);
            int curCnt = 0;
            for(auto x : cur) 
                curCnt += (x<=distanceThreshold);
            if(cityCount >= curCnt) 
                cityCount = curCnt, cityNumber = i;
        }
        return cityNumber;
    }
};