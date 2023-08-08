class DSU {
public:
    vector<int> rank, par;
    DSU(int n) {
        rank.resize(n);
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
    }
    int findPar(int u) {
        return (par[u] == u) ? u : par[u] = findPar(par[u]);
    }
    void unite(int u, int v) {
        par[findPar(u)] = findPar(v);
    }
    bool inComponent(int u, int v) {
        return findPar(u) == findPar(v);
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int q = queries.size();
        int m = edgeList.size();
        int j = 0;
        for (int i = 0; i < q; i++) {
            queries[i].push_back(i);
        }
        sort(begin(edgeList),end(edgeList),[&](auto &a, auto &b){return a[2] < b[2];});
        sort(begin(queries),end(queries),[&](auto &a, auto &b){return a[2] < b[2];});
        vector<bool> ans(q);
        DSU obj(n);
        for (int i = 0; i < q; ++i) {
            int u = queries[i][0];
            int v = queries[i][1];
            int maxLimit = queries[i][2];
            int index = queries[i][3];
            while (j < m && edgeList[j][2] < maxLimit) {
                obj.unite(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            ans[index] = (obj.inComponent(u, v));
        }
        return ans;
    }
};