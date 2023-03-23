class Solution {
public:
    int solve(int s, int d, vector<pair<long long,long long>> adj[], vector<long long> &dist, vector<int> &ans) {
        if(s==d) return 1;
        if(ans[s]!=-1) return ans[s];
        int cnt = 0;
        for(auto it : adj[s]) {
            if(dist[it.first] < dist[s]) {
                cnt = (cnt + solve(it.first, d, adj, dist, ans)) % 1000000007;
            }
        }
        return ans[s]=cnt;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        vector<pair<long long,long long>> adj[n+1];
        for(auto it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<long long> dist(n+1, 2e9);
        dist[n] = 0; 
        priority_queue<pair<long long,long long>> pq;
        pq.push({0, n});
        
        while(pq.size()) {
            auto cur = pq.top();
            pq.pop();
            int node = cur.second;
            for(auto it : adj[node]) {
                if(dist[it.first] > dist[node] + it.second) {
                    dist[it.first] = dist[node] + it.second;
                    pq.push({-dist[it.first], it.first});
                }
            }
        }
        vector<int> ans(n+1, -1);
        return solve(1, n, adj, dist, ans);
    }
};