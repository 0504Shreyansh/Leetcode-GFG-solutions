class DisjointSet {
    public:
    vector<int> rank;
    vector<int> parent;
    int components;
    DisjointSet(int n) {
        components = n;
        rank.resize(n+1);
        for(int i = 0; i <= n; i++) 
            parent.push_back(i);
    }
    int findParent(int u) {
        return (u==parent[u]) ? u : parent[u] = findParent(parent[u]);
    }
    int unite(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if(up != vp) {
            if(rank[up] < rank[vp])
                parent[up] = vp;
            else if(rank[up] > rank[vp])
                parent[vp] = up;
            else {
                parent[up] = vp;
                rank[up]++;
            }
            components--;
            return 1;
        }
        return 0;
    }
    bool isConnected() {
        return (components == 1);
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Create 2 different graphs
        DisjointSet Alice(n), Bob(n);
        int requiredEdges = 0;
        // Give priority to the type 3 edges first
        // Make graph using the type 3 edges
        for(auto edge : edges) {
            if(edge[0] == 3) {
                requiredEdges += Alice.unite(edge[1], edge[2]) 
                    | Bob.unite(edge[1], edge[2]);
            }
        }
        // Then try including other edegs
        // If they are not in the same component then increment counter
        for(auto edge : edges) {
            if(edge[0] == 1) {
                requiredEdges += Alice.unite(edge[1], edge[2]);
            }
            else if(edge[0] == 2) {
                requiredEdges += Bob.unite(edge[1], edge[2]);
            }
        }
        
        if(Alice.isConnected() && Bob.isConnected()) {
            return edges.size() - requiredEdges;
        }
        
        // Both have 1 components each, then only possile to remove some edges
        return -1;
    }
};