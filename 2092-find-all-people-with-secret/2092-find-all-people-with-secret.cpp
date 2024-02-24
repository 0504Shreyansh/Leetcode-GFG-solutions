class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int, int>> graph[n];
        for (auto &it : meetings) {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        vector<int> vis(n);
        while (pq.size()) {
            auto [time, person] = pq.top();
            pq.pop();
            if (vis[person]) 
                continue;
            vis[person] = 1;
            for (auto &[neigh, newTime] : graph[person]) {
                if (!vis[neigh] && -time <= newTime) {
                    pq.push({-newTime, neigh});
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};