class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<int> adj[n];
        vector<int> indegree(n);
        for (auto &it : roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++, indegree[it[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }
        vector<int>people(n, 1);
        long long ans = 0;
        while (q.size()) {
            int size = q.size();
            while (size--) {
                int u = q.front();
                q.pop();
                if (u == 0) break;
                ans += (people[u] + seats - 1) / seats;
                for (int &v : adj[u]) {
                    people[v] += people[u];
                    if (--indegree[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }
        return ans;
    }
};