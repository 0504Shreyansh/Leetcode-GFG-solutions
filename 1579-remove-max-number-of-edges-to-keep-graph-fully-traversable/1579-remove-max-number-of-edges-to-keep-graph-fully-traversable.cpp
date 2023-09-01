class DSU {
public:
    vector<int> rank, par;
    DSU(int n) {
        rank.resize(n);
        for (int i = 0; i < n; i++) 
            par.push_back(i);
    }
    int find(int u) {
        return (par[u] == u) ? u : par[u] = find(par[u]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return ;
        if (rank[u] < rank[v]) {
            par[u] = v;
        } else if (rank[u] > rank[v]) {
            par[v] = u;
        } else {
            par[u] = v;
            rank[v]++;
        }
    }
    bool sameComponent(int u, int v) {
        return find(u) == find(v);
    }
    bool comps(int n) {
        int component = 0;
        for (int i = 0; i < n; i++) 
            component += (par[i] == i);
        return component == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(rbegin(edges), rend(edges));
        int edgeCount = 0;
        DSU alice(n), bob(n);
        for (auto &it : edges) {
            int type = it[0], u = it[1] - 1, v = it[2] - 1;        
            if (type == 3) {
                if (!alice.sameComponent(u, v) || !bob.sameComponent(u, v)) {
                    alice.unite(u, v), bob.unite(u, v);
                } else {
                    edgeCount++;
                }
            } else if (type == 2) {
                if (!bob.sameComponent(u, v)) {
                    bob.unite(u, v);
                } else {
                    edgeCount++;
                }
            } else {
                if (!alice.sameComponent(u, v)) {
                    alice.unite(u, v);
                } else {
                    edgeCount++;
                }
            }
        }
        return (alice.comps(n) && bob.comps(n)) ? edgeCount : -1;
    }
};