//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int ans = 0;
  vector<pair<vector<int>,int>> vv;
    void dfs(int s, vector<pair<int,int>> adj[], vector<int> &visited, int steps, int n, vector<int> v) 
    {
        v.push_back(s);
        if(s==n-1) 
        {
            vv.push_back({v, steps});
            return ;
        }
        visited[s] = 1;
        for (auto i:adj[s]) 
        {
            if(!visited[i.first]) 
            {
                steps += i.second;
                dfs(i.first, adj, visited, steps, n, v);
                steps -= i.second;
            }
        }
        visited[s] = 0;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n];
        for(auto e:roads) 
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> visited(n, 0);
        vector<int> v;
        dfs(0, adj, visited, 0, n, v);

        
        // for(auto i:vv) {
        //     for(auto j:i.first) cout<<j<<' '; cout<<endl<<i.second<<endl;
        // }
        
        int cnt = INT_MAX;
        for (auto i:vv) {
            if(i.second<cnt)
                cnt = i.second;
        }
        for (auto i:vv) {
            if(i.second==cnt) 
                ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends