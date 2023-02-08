//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        K++;
        while(K--) {
            vector<int> curr = dist;
            for (auto f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (w + dist[u] < curr[v]) {
                    curr[v] = dist[u] + w;
                }
            }
            dist = curr;
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