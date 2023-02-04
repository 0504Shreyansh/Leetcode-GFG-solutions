//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void dfs(vector<vector<int>> &grid, vector<vector<int>>&visited, int i, int j) {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||visited[i][j]||!grid[i][j])
            return ;
        visited[i][j] = 1;
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i,j-1);
    }
    public:
    int closedIslands(vector<vector<int>>& matrix, int n, int m) 
    {
        vector<vector<int>> visited(n, vector<int> (m));
        
        for(int i=0;i<n;i++) {
            if(!visited[i][0] && matrix[i][0]) 
                dfs(matrix,visited,i,0);
            if(!visited[i][m-1] && matrix[i][m-1]) 
                dfs(matrix,visited,i,m-1);
        }
        for(int i=0;i<m;i++) {
            if(!visited[0][i] && matrix[0][i]) 
                dfs(matrix,visited,0,i);
            if(!visited[n-1][i] && matrix[n-1][i]) 
                dfs(matrix,visited,n-1,i);
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && matrix[i][j]) {
                    ans++;
                    dfs(matrix,visited,i,j);
                }
            }
        }
        return ans;
        
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