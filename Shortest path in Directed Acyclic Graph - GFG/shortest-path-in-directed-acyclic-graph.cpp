//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(N, -1);
        queue<int> Q({0});
        dist[0] = 0;
        while (Q.size()) {
            int size = Q.size();
            while (size--) {
                int u = Q.front();
                Q.pop();
                for (auto &x : adj[u]) {
                    int v = x.first;
                    int w = x.second;
                    if (dist[v] == -1 || dist[v] > dist[u] + w) {
                        Q.push(v);
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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