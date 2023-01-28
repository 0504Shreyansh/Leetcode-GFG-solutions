//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool dfs(vector<int> adj[], vector<int> &color, int sr, int col) {
        color[sr] = col;
        for(auto nbr:adj[sr]) {
            if(color[nbr]==-1) {
                if(!dfs(adj,color,nbr,1-col))
                    return false;
            }
            else if(color[sr]==color[nbr])
                return false;
            color[nbr] = !col;
        }
        return true;
    }    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> color(V, -1);
	    
	    for(int i=0;i<V;i++) {
	        if(color[i]==-1) {
	            if(!dfs(adj,color,i,0))
	                return false;
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends