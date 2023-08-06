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
        if (u != v)
            par[u] = par[v] = min(u, v);
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(begin(meetings),end(meetings),[&](auto &a, auto &b) {
            return a[2] < b[2];
        });
        int m = meetings.size();
        DSU obj(n);
        obj.unite(0, firstPerson);
        for (int i = 0; i < m; i++) {
            int time = meetings[i][2];
            int index = i;
            while (i < m && meetings[i][2] == time) {
                int u = meetings[i][0], v = meetings[i][1];
                obj.unite(u, v);
                i++;
            }
            while (index < i) {
                int u = meetings[index][0], v = meetings[index][1];
                if (obj.findPar(u) != 0 && obj.findPar(v) != 0) {
                    obj.par[u] = u;
                    obj.par[v] = v;
                }
                index++;
            }
            i--;
        }
        vector<int> ans;
        int parent = obj.par[0];
        for (int i = 0; i < n; i++) {
            if (obj.findPar(i) == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};