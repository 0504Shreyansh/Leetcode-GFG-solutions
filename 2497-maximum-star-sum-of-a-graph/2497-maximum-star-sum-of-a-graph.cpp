class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<priority_queue<int>> G(n);
        for (auto &it : edges) {
            G[it[1]].push(vals[it[0]]);
            G[it[0]].push(vals[it[1]]);
        }
        int res = -1e9;
        for (int i = 0; i < n; i++) {
            priority_queue<int> pq = G[i];
            int size = k;
            int cur = vals[i];
            while (size-- && pq.size() && pq.top() > 0) {
                cur += pq.top();
                pq.pop();
            }
            res = max(res, cur);
        }
        return res;
    }
};