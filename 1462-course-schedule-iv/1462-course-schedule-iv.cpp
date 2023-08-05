class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> adj[n];
        vector<int> indegree(n);
        for (auto &it : prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<vector<bool>> table(n, vector<bool> (n, false));
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto &v : adj[u]) {
                table[u][v] = true;
                for (int i = 0; i < n; i++) 
                    if (table[i][u] == 1)
                        table[i][v] = 1;
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        vector<bool> ans;
        for (auto &it : queries) {
            ans.push_back(table[it[0]][it[1]]);
        }
        return ans;
    }
};