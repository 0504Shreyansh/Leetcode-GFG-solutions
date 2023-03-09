class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> graph[n];
        for(auto e : roads) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        
        vector<long> dist(n, 1e15), ways(n);
        dist[0] = 0, ways[0] = 1;
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<pair<long,int>>> pq;
        pq.push({0, 0});
        
        while(pq.size()) {
            long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto x : graph[u]) {
                int v = x.first, w = x.second;
                // Update the distance
                // Update number of ways tyo reach the node v from u
                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                // Thus, v can also be reached by u, so add the number of ways u too
                else if(dist[v] == d + w)
                    ways[v] = (ways[v] + ways[u])%1000000007;
            }
        }     
        
        return ways[n-1];
    }
};