//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs(int u, vector<int> G[], vector<int>& vis, stack<int>& st) {
        vis[u] = 1;
        for (int &v : G[u]) {
            if (!vis[v]) {
                dfs(v, G, vis, st);
            }
        }
        st.push(u);
    }
    void dfs2(int u, vector<int> G[], vector<int>& vis) {
        vis[u] = 1;
        for (int &v : G[u]) {
            if (!vis[v]) {
                dfs2(v, G, vis);
            }
        }
    }
public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> G[V];
        for (int i = 0; i < V; i++) {
            for (auto &it : adj[i]) {
                G[i].push_back(it);
            }
        }
        stack<int> st;
        vector<int> vis(V);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, G, vis, st);
            }
        }
        vector<int> rG[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto &it : adj[i]) {
                rG[it].push_back(i);
            }
        }
        int ans = 0;
        while (st.size()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                ans++;
                dfs2(node, rG, vis);
            } 
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends