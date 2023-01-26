//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>&visited, int i, int j) {
        visited[i][j] = 1;
        int area = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        while(q.size()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            // cout<<x<<' '<<y<<endl;
            area++;
            for(int a=-1;a<2;a++) {
                for(int b=-1;b<2;b++) {
                    int nx = x+a, ny = y+b;
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&grid[nx][ny]) {
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return area;
    }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m));
        int maxArea = 0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j]) 
                    maxArea = max(maxArea, bfs(grid,visited,i,j));
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