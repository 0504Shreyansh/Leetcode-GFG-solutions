class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        for(auto e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        queue<int> q({0});
        vector<int> vis(n);
        vis[0] = 1;
        unordered_map<int,int> mp;
        for(auto e: restricted)
            mp[e]++;
    
        while(q.size()) {
            int x = q.size();
            while(x--) {
                int node = q.front();
                q.pop();
                for(auto e: adj[node]) {
                    if(!vis[e] && !mp[e]) {
                        vis[e] = 1, q.push(e);
                    }
                }
            }
        }
        
        int cnt = 0;
        for(auto e: vis) cnt+=e;
        return cnt;
    }
};