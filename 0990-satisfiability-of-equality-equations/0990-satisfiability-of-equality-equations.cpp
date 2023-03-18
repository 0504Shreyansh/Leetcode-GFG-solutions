class DisjointSet {
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findParent(int node) {
        return (parent[node]==node) ? node : parent[node] = findParent(parent[node]);
    }
    void unite(int u, int v) {
        int up = findParent(u), vp = findParent(v);
        if(up != vp) {
            if(rank[up] < rank[vp])
                parent[up] = vp;
            else if(rank[up] > rank[vp])
                parent[vp] = up;
            else {
                parent[vp] = up;
                rank[vp]++;
            }
        }
    }
    void uniteBySize(int u, int v) {
        int up = findParent(u), vp = findParent(v);
        if(up != vp) {
            if(size[up] < size[vp]) {
                parent[up] = vp;
                size[vp] += size[up];
            }
            else {
                parent[vp] = up;
                size[up] += size[vp]; 
            }
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        DisjointSet ds(26);
        
        for (auto e : equations) 
            if (e[1]=='=')
                ds.uniteBySize(e[0]-'a', e[3]-'a');
        
        for(auto e : equations) 
            if(e[1]=='!') 
                if(ds.findParent(e[0]-'a') == ds.findParent(e[3]-'a'))
                    return false;
        return true;
    }
};