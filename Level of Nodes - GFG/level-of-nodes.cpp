//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<int> q({0});
	    vector<int> visit(V);
	    visit[0] = 1;
	    int steps = 0;
	    while (q.size()) {
	        int size = q.size();
	        while (size--) {
	            int u = q.front();
	            q.pop();
	            if (u == X) return steps;
	            for (int &v : adj[u]) {
	                if (!visit[v]) {
	                    visit[v] = 1;
	                    q.push(v);
	                }
	            } 
	        }
	        steps++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends