//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
    int unite(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if(up != vp) {
            if(rank[up] < rank[vp]) {
                parent[up] = vp;
            }
            else if(rank[up] > rank[vp]) {
                parent[vp] = up;
            }
            else {
                rank[vp]++;
                parent[up] = vp;
            }
        }
    }
};


class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DisjointSet ds(V);
        vector<vector<int>> g;
        for(int i = 0; i < V; i++) {
            // cout<<i<<"->";
            for(auto edge : adj[i]) {
                int u = i, v = edge[0], w = edge[1];
                g.push_back({w, u, v});
                // cout<<u<<' '<<v<<' '<<w<<endl;
            }
        }
        sort(g.begin(),g.end());
        // cout<<endl;
        // for(int i = 0; i < g.size(); i++) {
        //     for(int j = 0; j < g[i].size(); j++) {
        //         cout<<g[i][j]<<' ';
        //     }cout<<endl;
        // }
        
        int cost = 0;
        for(int i = 0; i < g.size(); i++) {
            if(ds.findParent(g[i][1]) != ds.findParent(g[i][2])) {
                ds.unite(g[i][1], g[i][2]);
                cost += g[i][0];
            }
        }
        return cost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends