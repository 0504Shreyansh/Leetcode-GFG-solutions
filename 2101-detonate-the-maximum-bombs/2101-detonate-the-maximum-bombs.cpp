class Solution {
public:
    void dfs(int node, int &cnt, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        cnt++;
        for(auto nbr : adj[node]) 
            if(!vis[nbr])
                dfs(nbr, cnt, adj, vis);
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n + 1];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int x1 = bombs[i][0], x2 = bombs[j][0]; 
                int y1 = bombs[i][1], y2 = bombs[j][1]; 
                int r1 = bombs[i][2], r2 = bombs[j][2];
                long long dist = (1LL)*(x1 - x2) * (x1 - x2) + (1LL)*(y1 - y2) * (y1 - y2);
                long long actualDist = (1LL) * r1 * (1LL) * r1;
                bool isValid = (dist <= actualDist); 
                if(isValid) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans = 1;
        for(int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            if(!vis[i]) {
                int cnt = 0;
                dfs(i, cnt, adj, vis);
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
};