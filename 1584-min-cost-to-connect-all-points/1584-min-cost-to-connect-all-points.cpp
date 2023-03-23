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
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int res = 0;
        DisjointSet ds(n);
        vector<pair<int,pair<int,int>>> vp;
        
        for(int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i+1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                vp.push_back({dist, {i, j}});
            } 
        }
        
        sort(vp.begin(),vp.end());
        for(auto it : vp) {
            if(ds.findParent(it.second.first) != ds.findParent(it.second.second)) {
                ds.unite(it.second.first, it.second.second);
                res += it.first;
            }
        }
        
        
        return res;
    }
};