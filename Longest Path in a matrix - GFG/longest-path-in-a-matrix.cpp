//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<pair<int,int>> direction = {{-1, 0}, {1, 0}, {0, 1} ,{0, -1}};
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int cur = 1;
        for(auto k : direction) {
            int X = i + k.first;
            int Y = j + k.second;
            if (X >= 0 && X < grid.size() && Y >= 0 && Y < grid[0].size() && grid[X][Y] > grid[i][j]) {
                cur = max(cur,  1 +dfs(X, Y, grid, dp));
            }
        }
        return dp[i][j] = cur;
    }
    
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int ans = 1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, grid, dp));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends