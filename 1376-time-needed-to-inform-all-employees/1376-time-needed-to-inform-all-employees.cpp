class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<pair<int,int>> adjList[n];
        queue<pair<int,int>> q({{headID, -1}});
        vector<int> dist(n, 1e9);
        dist[headID] = informTime[headID];
        
        for(int i = 0; i < n; i++) {
            if(manager[i]!=-1) 
                adjList[manager[i]].push_back({i, informTime[i]});             
        }
        
        // for(int i = 0; i < n; i++) {
        //     cout<<i<<"->";
        //     for(auto j:adjList[i]) 
        //         cout<<j.first<<" "<<j.second<<", ";
        //     cout<<endl;
        // }
        
        while(q.size()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto cur = q.front();
                q.pop();
                int node = cur.first, parent = cur.second;
                for(auto adjNode: adjList[node]) {
                // Dijkstra algo 
                    if(dist[adjNode.first] > dist[node] + adjNode.second) {
                        dist[adjNode.first] = dist[node] + adjNode.second;
                        q.push({adjNode.first, node});
                    }
                }
            }
        }
        
        for(auto i:dist) cout<<i<<' '; cout<<endl;
        return *max_element(dist.begin(), dist.end());
    }
};