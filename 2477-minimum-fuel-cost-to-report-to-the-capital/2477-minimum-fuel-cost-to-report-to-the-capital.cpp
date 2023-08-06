class Solution {
private:
    int dfs(int node, int par, vector<int> adj[], int& seats, long long &ans) {
        int cur = 1;
        for (auto &adjNode : adj[node]) {
            if (par != adjNode) {
                cur += dfs(adjNode, node, adj, seats, ans);
            }
        }
        if (node > 0) {
            ans += (cur + seats - 1) / seats;
        }
        return cur;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<int> adj[n];
        for (auto &it : roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long ans = 0;
        dfs(0, -1, adj, seats, ans);
        return ans;
    }
};