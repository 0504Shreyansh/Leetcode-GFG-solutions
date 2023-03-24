class Solution {
public:
    int res = 0;
    void dfs(int node, vector<int> adj[], vector<int> &vis) {
        // Mark as visited
        vis[node] = 1;
        for (auto nbr : adj[node]) {
            // If node is unvisited
            if (!vis[abs(nbr)]) {
                // Just count the +ve nodes
                if(nbr > 0) res++;
                dfs(abs(nbr), adj, vis);
            } 
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
     
        vector<int> vis(n, 0);
        vector<int> adj[n];
        
        // Directed edge treated as +ve edge and inverse edge as -ve edge
        for (auto c : connections) { 
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        
        // Start dfs from 0
        // If the group of nodes can be reached by 0
        // i.e. we need reorder it (only +ve edges)
        // So that they reach to 0
        dfs(0, adj, vis);
        
        return res;
    }
};