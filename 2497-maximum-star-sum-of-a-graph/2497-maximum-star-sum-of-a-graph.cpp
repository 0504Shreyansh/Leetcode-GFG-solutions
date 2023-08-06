class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        priority_queue<int> adj[n];
        for (auto &it : edges) {
            adj[it[0]].push(vals[it[1]]);
            adj[it[1]].push(vals[it[0]]);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int K = k;
            int cur = vals[i];
            while (adj[i].size() && adj[i].top() > 0 && K--) {
                cur += adj[i].top();
                adj[i].pop();
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};