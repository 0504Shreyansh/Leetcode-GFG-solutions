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
                par[u] = v;
                rank[v]++;
            }
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        DSU obj(n);
        for (auto &it : requests) {
            int u = obj.findPar(it[0]), v = obj.findPar(it[1]);
            bool canBeFriends = true;
            for (auto &j : restrictions) {
                int p1 = obj.findPar(j[0]), p2 = obj.findPar(j[1]);
                if ((u == p1 && v == p2) || (u == p2 && v == p1)) {
                    canBeFriends = false;
                    break;
                }
            }
            if (canBeFriends) {
                obj.unite(it[0], it[1]);
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};