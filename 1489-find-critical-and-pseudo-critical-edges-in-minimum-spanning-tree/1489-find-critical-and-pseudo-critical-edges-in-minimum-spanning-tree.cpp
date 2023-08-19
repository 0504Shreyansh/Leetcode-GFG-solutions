class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
    int maxSize;
    DisjointSet(int n) {
        maxSize = 1;
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }
    int find(int u) {
        return (parent[u] == u) ? u : parent[u] = find(parent[u]);
    } 
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
            maxSize = max(maxSize, size[u]);
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }
        sort(begin(edges), end(edges), [&](auto &a, auto &b) {
            return a[2] < b[2];
        });
        
        // Kruksal algo
        int MST_wt = 0;
        DisjointSet obj(n);
        for (auto &edge : edges) {
            if (obj.unite(edge[0], edge[1])) {
                MST_wt += edge[2];
            }
        }
        
        // Check for critical and p_critical
        vector<vector<int>> ans(2);
        for (int i = 0; i < m; i++) {
            int new_MST_wt = 0;
            DisjointSet _obj(n);
            for (int j = 0; j < m; j++) {
                if (i == j) continue;
                if (_obj.unite(edges[j][0], edges[j][1])) {
                    new_MST_wt += edges[j][2];
                }
            }
            
            // incomplete graph or mst_wt increase
            if (_obj.maxSize < n || new_MST_wt > MST_wt) {
                ans[0].push_back(edges[i][3]);
            } else {
                int forcedWt = edges[i][2];
                DisjointSet ob(n);
                ob.unite(edges[i][0], edges[i][1]);
                for (int j = 0; j < m; j++) {
                    if (i == j) continue;
                    if (ob.unite(edges[j][0], edges[j][1])) {
                        forcedWt += edges[j][2];
                    }
                }
                if (forcedWt == MST_wt && ob.maxSize == n) {
                    ans[1].push_back(edges[i][3]);
                }
            }
        }
        return ans;
    }
};