class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> graph[n];
        vector<int> indegree(n);
        vector<int> maxTime(n, 0);
        for (auto &it : relations) {
            graph[it[0] - 1].push_back(it[1] - 1);
            indegree[it[1] - 1]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
            maxTime[i] = time[i];
        }
        int ans = 0;
        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    maxTime[v] = max(maxTime[v], time[v] + maxTime[u]);
                    if (--indegree[v] == 0) {
                        q.push(v);
                    }
                }
            }
        }
        return *max_element(begin(maxTime),end(maxTime));
    }
};