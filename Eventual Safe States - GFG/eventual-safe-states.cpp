//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> A[V], in(V);
        for (int i = 0; i < V; i++) {
            for (auto &j : adj[i]) {
                in[i]++;
                A[j].push_back(i);
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int &v : A[u]) {
                if (--in[v] == 0) {
                    q.push(v);
                }
            }
        }
        sort(begin(ans), end(ans));
        return ans;
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