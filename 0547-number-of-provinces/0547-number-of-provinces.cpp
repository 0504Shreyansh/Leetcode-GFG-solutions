class Solution {
public:
    void dfs(vector<int> adjList[], vector<int> &visited, int sr) {
        visited[sr] = 1;
        for(auto neighbour : adjList[sr]) {
            if(!visited[neighbour]) {
                dfs(adjList, visited, neighbour);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        int numberOfProvinces = 0;
        vector<int> adjList[n];
        //Create adjList
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i != j && isConnected[i][j]) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        //Visit every province and mark them as visited by dfs
        vector<int> visited(n);
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                numberOfProvinces++;
                dfs(adjList, visited, i);
            }
        }
        return numberOfProvinces;
    }
};