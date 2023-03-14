//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


// } Driver Code Ends
class Solution{
    public:
    int res = 0;
    void dfs(int node, int *duration, vector<int> adj[], int sum, vector<int>& vis) 
    {
        vis[node] = 1;
        sum += duration[node];
        res = max(res, sum);
        for(auto nbr : adj[node]) 
        {
            dfs(nbr, duration, adj, sum, vis);
        }
        vis[node] = 0;
    }
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        
        vector<int> adj[n];
        for(auto x : dependency)
            adj[x.first].push_back(x.second);
        
        vector<int> inDegree(n, 0);
        for(int i = 0; i < m; i++) 
            inDegree[dependency[i].second]++;
            
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(!inDegree[i])
                q.push(i);
        
        vector<int> topSort;
        while(q.size()) 
        {
            int front = q.front();
            q.pop();
            topSort.push_back(front);
            for(auto nbr : adj[front])
            {
                if(--inDegree[nbr]==0)
                    q.push(nbr);
            }
        }
        
        if(topSort.size() != n)
            return -1;
            
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++)
        {
            dfs(i, duration, adj, 0, vis);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends