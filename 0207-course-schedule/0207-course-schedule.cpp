class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // cyclic dependency --> can not finish
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        for(auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }
        queue<int> Q;
        for(int u = 0; u < n; u++) {
            if(inDegree[u] == 0) Q.push(u);
        }
        int count = 0;
        while(Q.size()) {
            int u = Q.front();
            Q.pop();
            count++;
            for(auto &v : adj[u]) {
                if(--inDegree[v] == 0) Q.push(v);
            }
        }
        return (count == n) ? true : false;
    }
};