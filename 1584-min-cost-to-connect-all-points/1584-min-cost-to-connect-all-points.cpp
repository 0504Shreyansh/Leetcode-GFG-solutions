class DSU {
private:
    vector<int> rank, par;
public:
    DSU(int n) {
        rank.resize(n);
        for (int i = 0; i < n; i++) 
            par.push_back(i);
    }
    int find(int u) {
        return (par[u] == u) ? u : par[u] = find(par[u]);
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (rank[u] < rank[v]) {
            par[u] = v; 
        } else if (rank[u] > rank[v]) {
            par[v] = u;
        } else {
            par[u] = v;
            rank[v]++;
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> P;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                P.push_back({dist, i, j}); 
            }
        }
        int cost = 0;
        sort(begin(P), end(P));
        DSU obj(n);
        for (auto &it : P) {
            int dist = it[0], u = it[1], v = it[2];
            if (obj.unite(u, v)) {
                  cost += dist;
            }
        }
        return cost;
    }
};