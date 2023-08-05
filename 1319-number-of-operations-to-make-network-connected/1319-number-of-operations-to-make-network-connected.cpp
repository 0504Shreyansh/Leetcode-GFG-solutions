class DSU {
public:
    vector<int> rank;
    vector<int> par;
    DSU(int n) {
        rank.resize(n);
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
    }
    int findPar(int u) {
        return (par[u] == u) ? u : par[u] = findPar(par[u]);
    }
    void unite(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                par[u] = v;
            } else if (rank[u] > rank[v]) {
                par[v] = u;
            } else {
                rank[u]++;
                par[v] = u;
            }
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& C) {
        DSU obj(n);
        int excess = 0;
        for (auto &it : C) {
            if (obj.findPar(it[0]) == obj.findPar(it[1])) {
                excess++;
            }
            obj.unite(it[0], it[1]);
        }
        int parents = 0;
        for (int i = 0; i < n; i++) {
            if (obj.par[i] == i) parents++;
        }
        return (C.size() >= n - 1) ? parents - 1 : -1;
    }
};