#define ll long long
class Solution {
public:
    ll ans = 0; 
    ll dfs(vector<int>& vis, int node, int seats, vector<int> adj[]){
        vis[node] = 1; 
        ll count = 1; 
        for(auto it : adj[node]){
            if(!vis[it])
                count += dfs(vis, it, seats, adj);
        }
        
        ll x = count / seats;
        if(count % seats) 
            x++;
        if(node) 
            ans += x;
        return count; 
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> adj[n+1], vis(n+1); 
        
        // create adjacency list
        for(auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfs(vis, 0, seats, adj);
        return ans;
    }
};