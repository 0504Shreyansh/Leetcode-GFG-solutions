class DSU {
    vector<int> rank;
    vector<int> par;
public:
    DSU(int n) {
        rank.resize(n);
        par.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i;
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
                par[u] = v;
                rank[v]++;
            }
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> p;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                p.push_back({dist, i, j});
            }
        }
        sort(begin(p),end(p));
        DSU obj(n);
        int ans = 0;
        for (auto &it : p) {
            if (obj.findPar(it[1]) != obj.findPar(it[2])) {
                ans += it[0];
            }
            obj.unite(it[1], it[2]);
        }
        return ans;
    }
};