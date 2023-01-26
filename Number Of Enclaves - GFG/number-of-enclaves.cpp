//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j) {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||vis[i][j]||!grid[i][j])
            return ;
        vis[i][j] = 1;
        dfs(grid,vis,i+1,j);
        dfs(grid,vis,i-1,j);
        dfs(grid,vis,i,j+1);
        dfs(grid,vis,i,j-1);
    }
    public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m));
        int number_of_enclaves = 0;
        
        for(int i=0;i<n;i++) {
            if(!visited[i][0] && grid[i][0])
                dfs(grid,visited,i,0);
            if(!visited[i][m-1] && grid[i][m-1])
                dfs(grid,visited,i,m-1);
        }
        for(int i=0;i<m;i++) {
            if(!visited[0][i] && grid[0][i])
                dfs(grid,visited,0,i);
            if(!visited[n-1][i] && grid[n-1][i])
                dfs(grid,visited,n-1,i);
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j])
                    number_of_enclaves++;
            }
        }
        
        return number_of_enclaves;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends