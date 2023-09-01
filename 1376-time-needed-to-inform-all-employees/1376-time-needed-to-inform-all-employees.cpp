class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> G[n];
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                G[manager[i]].push_back(i);
            }
        }
        int ans = informTime[headID];
        queue<int> q({headID});
        while (q.size()) {
            int size = q.size();
            int id = q.front();
            q.pop();
            for (int &v : G[id]) {
                q.push(v);
                informTime[v] += informTime[id];
                ans = max(ans, informTime[v]);
            }
        }
        return ans;
    }
};