class Solution {
public:
    void dfs(int node, vector<int> adjList[], int n, vector<int> &vis) {
        vis[node] = 1;
        for(auto adjNode: adjList[node]) {
            if(!vis[adjNode])
                dfs(adjNode, adjList, n, vis);
        }
    }
    int makeConnected(int numberOfNodes, vector<vector<int>>& connections) {
        
        //Create adjList
        int numberOfEdges = connections.size();
        int cntOfDisconnectedComps = 0;
        vector<int> adjList[numberOfNodes], vis(numberOfNodes);
        
        for(auto edge: connections) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        for(int node = 0; node < numberOfNodes; node++) {
            if(!vis[node]) {
                cntOfDisconnectedComps++;
                dfs(node, adjList, numberOfNodes, vis);
            }
        }
        
        return (numberOfNodes-1 > numberOfEdges) ? -1 : (cntOfDisconnectedComps-1);
        
    }
};