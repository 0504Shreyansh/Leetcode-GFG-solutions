class Solution {
private:
    void dfs(vector<int> adjList[], vector<int> &visited, int sr, int &cnt) {
        visited[sr] = 1;
        cnt++; 
        for(auto neighbour: adjList[sr]) {
            if(!visited[neighbour])
                dfs(adjList, visited, neighbour, cnt);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        long long pairs = 0;
        vector<int> adjList[n];
        vector<int> visited(n);
        
        //Create adjList 
        for(auto e: edges) {
            int u = e[0], v = e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        int remainingNumberOfNodes = n;
        for(int i=0;i<n;i++) {
            int currNumberOfNodes = 0;
            if(!visited[i]) {
                dfs(adjList, visited, i, currNumberOfNodes);
                remainingNumberOfNodes -= currNumberOfNodes;
                // cout<<currNumberOfNodes<<' '<<remainingNumberOfNodes<<endl;
                pairs += (1LL*currNumberOfNodes)*(1LL*remainingNumberOfNodes);
            }
        }
        
        return pairs;
    }
};