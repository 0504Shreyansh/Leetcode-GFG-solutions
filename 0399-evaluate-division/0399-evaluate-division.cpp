class Solution {
public:
    double dijkstra(unordered_map<string,vector<pair<string,double>>>& adj, string start, string end) {
        unordered_map<string,double> dist;
        for(auto it : adj)
            dist[it.first] = 2e9*1.0;
        if(dist.find(end) == dist.end() || dist.find(start) == dist.end())
            return -1.0;
        dist[start] = 1.0;
        priority_queue<pair<double,string>> Q;
        Q.push({1.0, start});
        while(!Q.empty()) {
            auto cur = Q.top();
            Q.pop();
            string node = cur.second;
            double dis = cur.first;
            for(auto neighbour : adj[node]) {
                if(dist[neighbour.first] > dist[node] * neighbour.second) {
                    dist[neighbour.first] = dist[node] * neighbour.second;
                    Q.push({-dist[neighbour.first], neighbour.first});
                }
            }
        }
        return dist[end] == 2e9*1.0 ? -1 : dist[end];
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 1.0/w});
        }
        vector<double> ans;
        for(auto q : queries) {
            string start = q[0];
            string end = q[1];
            double dist = dijkstra(adj, start, end);
            ans.push_back(dist);
        }
        return ans;
    }
};