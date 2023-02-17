class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //Create adjList
        vector<pair<int,int>> adjList[n+1];
        for (auto e : times)
            adjList[e[0]].push_back({e[1], e[2]});
        
        vector<int> time(n+1, 1e9);
        queue<pair<int,int>> q;
        q.push({k, 0});
        time[k] = time[0] = 0; 
        
        while(q.size()) {
            auto node = q.front();
            int curNode = node.first, w = node.second;
            q.pop();
            for (auto e : adjList[curNode]) {
                int adjNode = e.first, wt = e.second;
                if (time[adjNode] > time[curNode] + wt) {
                    time[adjNode] = time[curNode] + wt;
                    q.push({adjNode, time[adjNode]});
                    // for(auto i:time) cout<<i<<' '; cout<<endl;
                    // cout<<adjNode<<endl;
                }
            }
        }
        
        for (auto t : time) {
            if(t==1e9)
                return -1;
        }
        
        return *max_element(time.begin(), time.end());    
    }
};