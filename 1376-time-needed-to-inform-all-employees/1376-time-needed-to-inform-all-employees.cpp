class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<pair<int,int>> adj[n];
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) 
                adj[manager[i]].push_back({i, informTime[i]});             
        }
        queue<int> Q;
        Q.push(headID);  
        vector<int> time(n, 1e9);
        time[headID] = informTime[headID];
        while(Q.size()) {
            int size = Q.size();
            while(size--) {
                int emp = Q.front();
                Q.pop();
                for(auto e : adj[emp]) {
                    int nbrEmp = e.first;
                    int neededTime = e.second;
                    if(time[nbrEmp] > time[emp] + neededTime) {
                        time[nbrEmp] = time[emp] + neededTime;
                        Q.push(nbrEmp);
                    }
                }
            }
        }
        return *max_element(begin(time),end(time));
    }
};