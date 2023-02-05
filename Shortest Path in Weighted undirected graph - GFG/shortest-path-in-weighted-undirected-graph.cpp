//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        //Create adjList
        vector<pair<int,int>> adj[n+1];
        for(auto i:edges) {
            int u = i[0], v = i[1], w = i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        //Initialise all the required DS
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, 1});
        vector<int> dist(n+1, 1e9);
        dist[1] = 0;
        vector<vector<int>> paths(n+1);
        paths[1].push_back(1);
        
        //Find the minimum distances and and shortest paths
        while(pq.size()) {
            int u = pq.top().second;
            vector<int> vec = paths[u];
            pq.pop();
            for(auto e: adj[u]) {
                int v = e.first, w = e.second;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                    vec.push_back(v);
                    paths[v] = vec;
                    vec.pop_back();
                }
            }
        }

        //If src and dest are on diff comps, return -1 else return the path
        if(paths[n].size()==0) return {-1};
        return paths[n];
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends