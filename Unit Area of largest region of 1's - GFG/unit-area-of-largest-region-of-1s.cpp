//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>&visited, int x, int y, int &area) {
        visited[x][y] = 1;
        int n = grid.size(), m = grid[0].size();
        area++;
        for(int a=-1;a<2;a++) {
            for(int b=-1;b<2;b++) {
                int nx = x+a, ny = y+b;
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&grid[nx][ny]) 
                    dfs(grid,visited,nx,ny,area);
            }
        }
    }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m));
        int maxArea = 0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j]) {
                    int area = 0;
                    dfs(grid,visited,i,j,area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends