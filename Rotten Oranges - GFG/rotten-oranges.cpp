//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    void print(vector<vector<int>> &grid) {
        for(auto i:grid) {
            for(auto j:i) cout<<j<<' ';
            cout<<endl;
        }
    }
    void bfs(vector<vector<int>> &mat, queue<pair<int,int>> &q, int &time) {
    int n = mat.size(), m = mat[0].size();
    while(q.size()) {
        int size = q.size();
        bool f = false;
        for(int i=0;i<size;i++) {
            int x = q.front().first, y = q.front().second;
            // cout<<x<<' '<<y<<endl;
            q.pop();
            if(x+1<n && mat[x+1][y]==1) {
                f = true; q.push({x+1,y}); mat[x+1][y] = 2;
            }
            if(y+1<m && mat[x][y+1]==1) {
                f = true; q.push({x,y+1}); mat[x][y+1] = 2;
            }
            if(x-1>=0 && mat[x-1][y]==1) {
                f = true; q.push({x-1,y}); mat[x-1][y] = 2;
            }
            if(y-1>=0 && mat[x][y-1]==1) {
                f = true; q.push({x,y-1}); mat[x][y-1] = 2; 
            }
        }
        if(f) time++;
        // print(mat);
    }
}
    int orangesRotting(vector<vector<int>>& grid) {
        
        int ans = 0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==2) 
                    q.push({i,j});
            } 
        }
        
        bfs(grid,q,ans);
        // print(grid);
        for(auto i:grid) {
            for(auto j:i) {
                if(j==1) return -1;
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends