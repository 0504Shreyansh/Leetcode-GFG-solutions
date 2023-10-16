//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int dirs[5] = {0, -1, 0, 1, 0};
int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int &color) {
    int curr = 1;
    grid[i][j] = color;
    for (int k = 0; k < 4; k++) {
        int X = i + dirs[k], Y = j + dirs[k + 1];
        if (X >= 0 && X < n && Y >= 0 && Y < m && grid[X][Y] == 1) {
            curr += dfs(X, Y, n, m, grid, color);
        }
    }
    return curr;
}

int largestIsland(vector<vector<int>>& grid) 
{
    map<int, int> AREAS;
    int n = grid.size(), m = grid[0].size();
    int color = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                int area = dfs(i, j, n, m, grid, color);
                AREAS[color] = area;
                color++;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 0) {
                int currArea = 1;
                set<int> found;
                for (int k = 0; k < 4; k++) {
                    int X = i + dirs[k], Y = j + dirs[k + 1];
                    if (X >= 0 && X < n && Y >= 0 && Y < m) {
                        if (!found.count(grid[X][Y])) {
                            currArea += AREAS[grid[X][Y]];
                            found.insert(grid[X][Y]);
                        }
                    }
                }
                ans = max(ans, currArea);
            }
        }
    }

    return (ans == 0) ? n * m : ans;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends