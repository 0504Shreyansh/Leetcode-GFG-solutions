class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for (auto &it : roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int max_rank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int curr_rank = adj[i].size() + adj[j].size();
                for (auto &it : adj[j]) {
                    if (it == i) {
                        curr_rank--;
                        break;
                    }
                }
                max_rank = max(max_rank, curr_rank);
            }
        }
        return max_rank;
    }
};