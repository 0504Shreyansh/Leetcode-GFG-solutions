//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    public:
    vector<int> dijkstra(vector<pair<int,int>> adj[], int n, int i) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, i});
        vector<int> dist(n, 1e9);
        dist[i] = 0;
        while(pq.size()) {
            int d = pq.top().first, node = pq.top().second;
            pq.pop();
            for(auto e: adj[node]) {
                if(dist[e.first] > dist[node] + e.second) {
                    dist[e.first] = dist[node] + e.second;
                    pq.push({dist[e.first], e.first});
                }
            }
        }
        return dist;
    } 

    int findCity(int n, int m, vector<vector<int>>& edges, int d) {
        vector<pair<int,int>> adj[n];
        for(auto e: edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        int cityNumber = -1, cityCount = INT_MAX;
        for(int i = 0; i < n; i++) {
            vector<int> dist = dijkstra(adj, n, i);
            int cnt = 0;
            for(auto dis: dist) 
                cnt += (dis <= d); 
            if(cityCount >= cnt) {
                cityCount = cnt;
                cityNumber = i;
            }       
        } 
        return cityNumber;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends