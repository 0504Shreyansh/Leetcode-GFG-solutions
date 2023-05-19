class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int>& color, int c) {
        color[node] = c;
        for(auto neighbour : adj[node]) {
            if(color[node] == color[neighbour]) {
                return false;
            }
            if(color[neighbour] == -1) {
                if(!dfs(neighbour, adj, color, !c)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) {
            return true;
        }
        vector<int> adj[n];
        for(int i = 0; i < n; i++) {
            for(auto j : graph[i])
                adj[i].push_back(j);
        }
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(!dfs(i, adj, color, 0)) {
                    return false;
                }
            }
        }
        return true;
    }
};