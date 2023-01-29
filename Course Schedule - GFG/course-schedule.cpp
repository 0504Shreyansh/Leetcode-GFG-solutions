//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adjList[n];
        for(int i=0;i<m;i++)
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
        vector<int> in(n);
        queue<int> q;
        for(int i=0;i<n;i++) {
            for(auto e: adjList[i]) 
                in[e]++;
        }
        
        for(int i=0;i<n;i++) {
            if(!in[i])
                q.push(i);
        }
        
        vector<int> course;
        while(q.size()) {
            int node = q.front();
            q.pop();
            course.push_back(node);
            for(auto e: adjList[node]) {
                --in[e];
                if(!in[e])
                    q.push(e);
            }
        }
        
        if(course.size() != n)
            course.clear();
        return course;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends