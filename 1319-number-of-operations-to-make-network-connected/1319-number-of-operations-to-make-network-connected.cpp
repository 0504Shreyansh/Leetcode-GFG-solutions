class DisjointSet {
    public: 
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) 
            parent[i] = i;
    }
    int findParent(int node) {
        return (node==parent[node]) ? node : parent[node]=findParent(parent[node]);
    }
    void unite(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if(up != vp) {
            if(rank[up] < rank[vp]) 
                parent[up] = vp;
            else if(rank[up] > rank[vp])
                parent[vp] = up;
            else {
                parent[up] = vp;
                rank[vp]++;
            }
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int res = 0;
        DisjointSet ds(n);
        for(auto it : connections) 
            if(ds.findParent(it[0]) != ds.findParent(it[1])) 
                ds.unite(it[0], it[1]);
    
        for(int i = 0; i < n; i++) 
            res += (ds.parent[i]==i);
        
        return (connections.size() >= n-1) ? res-1 : -1;
    }
};