//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool dfs(vector<int> adj[], vector<int>&pathVis, int start, vector<int> &safeNodes) {
        pathVis[start] += 2;
        for(auto nbr: adj[start]) {
            if(!pathVis[nbr] && dfs(adj,pathVis,nbr,safeNodes))
                return true;
            else if(pathVis[nbr]==2) 
                return true;
        }
        safeNodes.push_back(start);
        pathVis[start]--;
        return false;
    }  
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int> pathVis(V);
        vector<int> safeNodes;
        
        for(int i=0;i<V;i++) {
            if(!pathVis[i])
                dfs(adj,pathVis,i,safeNodes);
        }

        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends