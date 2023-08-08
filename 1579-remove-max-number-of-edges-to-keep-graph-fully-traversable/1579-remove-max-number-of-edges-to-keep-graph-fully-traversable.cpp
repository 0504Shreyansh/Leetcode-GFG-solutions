class DSU {
public:
    vector<int> rank;
    vector<int> par;
    DSU(int n) {
        rank.resize(n);
        for (int i = 0; i < n; i++) 
            par.push_back(i);
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
                rank[v]++;
                par[u] = v;
            }
        }
    }
    int comp() {
        int comps = 0;
        for (int i = 0; i < par.size(); i++) {
            comps += (par[i] == i);
        }
        return comps == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n), bob(n);
        sort(rbegin(edges),rend(edges));
        int ans = 0;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][1] - 1, v = edges[i][2] - 1;
            if (edges[i][0] == 1) {
                if (alice.findPar(u) != alice.findPar(v)) {
                    alice.unite(u, v);
                } else {
                    ans++;
                }
            } else if (edges[i][0] == 2) {
                if (bob.findPar(u) != bob.findPar(v)) {
                    bob.unite(u, v);
                } else {
                    ans++;
                }
            } else {
                if (alice.findPar(u) != alice.findPar(v) ||
                        bob.findPar(u) != bob.findPar(v)) {
                    alice.unite(u, v);
                    bob.unite(u, v);
                } else {
                    ans++;
                }
            }
        }
        return (alice.comp() == 1 && bob.comp() == 1) ? ans : -1;
    }
};