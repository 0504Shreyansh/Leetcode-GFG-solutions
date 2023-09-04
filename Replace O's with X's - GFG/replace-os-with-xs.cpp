//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dirs[5] = {0, -1, 0, 1, 0};
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& visit, bool change) {
        visit[i][j] = 1;
        if (change) grid[i][j] = 'X';
        for (int k = 0; k < 4; k++) {
            int X = i + dirs[k], Y = j + dirs[k + 1];
            if (X >= 0 && X < n && Y >= 0 && Y < m && !visit[X][Y] && grid[X][Y] == 'O') {
                dfs(X, Y, n, m, grid, visit, change);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        vector<vector<int>> visit(n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O' && !visit[i][0]) dfs(i, 0, n, m, grid, visit, false);
            if (grid[i][m - 1] == 'O' && !visit[i][m - 1]) dfs(i, m - 1, n, m, grid, visit, false);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O' && !visit[0][j]) dfs(0, j, n, m, grid, visit, false);
            if (grid[n - 1][j] == 'O' && !visit[n - 1][j]) dfs(n - 1, j, n, m, grid, visit, false);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O' && !visit[i][j]) {
                    dfs(i, j, n, m, grid, visit, true);
                }
            }
        }
        return grid;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends