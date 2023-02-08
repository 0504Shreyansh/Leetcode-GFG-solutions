//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        //Create adjList
        vector<pair<int,int>> adjList[n];
        for (auto e : flights) 
        {
            int u = e[0], v = e[1], w = e[2];
            adjList[u].push_back({v, w});
        }
        
        vector<int> dist(n, 1e9);
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src, 0}});
        dist[src] = 0;
        
        while(q.size()) 
        {
            auto curr = q.front();
            q.pop();
            int stops = curr.first, node = curr.second.first, cost = curr.second.second;
            //Valid answer
            if(stops <= K) 
            {
                for (auto e : adjList[node]) 
                {
                    int v = e.first, w = e.second;
                    if(dist[v] > cost + w)
                    {
                        dist[v] = cost + w;
                        q.push({stops+1, {v, dist[v]}});
                    }
                }
                
            }
        }
        
        return dist[dst]==1e9 ? -1 : dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends