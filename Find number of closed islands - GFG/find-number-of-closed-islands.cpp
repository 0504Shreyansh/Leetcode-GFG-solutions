//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    vector<pair<int,int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[i][j] = 1;
        for(auto v : direction) {
            int newX = i + v.first;
            int newY = j + v.second;
            if(newX >= 0&& newX < grid.size() && newY >= 0 && newY < grid[0].size() && !vis[newX][newY] && grid[newX][newY] == 1) {
                dfs(newX, newY, grid, vis);
            } 
        }
    }
    int closedIslands(vector<vector<int>>& grid, int N, int M) {
        vector<vector<int>> vis(N, vector<int> (M));
        for(int i = 0; i < N; i++) {
            if(grid[i][0] == 1 && !vis[i][0]) dfs(i, 0, grid, vis);
            if(grid[i][M - 1] == 1 && !vis[i][M - 1]) dfs(i, M - 1, grid, vis);
        }
        for(int j = 0; j < M; j++) {
            if(grid[0][j] == 1 && !vis[0][j]) dfs(0, j, grid, vis);
            if(grid[N - 1][j] == 1 && !vis[N - 1][j]) dfs(N - 1, j, grid, vis);
        }
        
        int closedIslandsCount = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    closedIslandsCount++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return closedIslandsCount;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends