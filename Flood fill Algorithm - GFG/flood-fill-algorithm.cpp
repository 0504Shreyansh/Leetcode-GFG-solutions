//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void bfs(vector<vector<int>> &image, vector<vector<int>>&vis, 
                            int sr, int sc, int n, int m, int val, int newColor) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        while(q.size()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            image[i][j] = newColor;
            if(i+1<n && !vis[i+1][j] && image[i+1][j]==val) {
                vis[i+1][j] = 1;
                q.push({i+1,j});
            }
            if(i-1>=0 && !vis[i-1][j] && image[i-1][j]==val) {
                vis[i-1][j] = 1;
                q.push({i-1,j});
            }
            if(j+1<m && !vis[i][j+1] && image[i][j+1]==val) {
                vis[i][j+1] = 1;
                q.push({i,j+1});
            }
            if(j-1>=0 && !vis[i][j-1] && image[i][j-1]==val) {
                vis[i][j-1] = 1;
                q.push({i,j-1});
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n = image.size(), m = image[0].size();
        int val = image[sr][sc];
        vector<vector<int>> vis(n,vector<int>(m));
        
        bfs(image,vis,sr,sc,n,m,val,newColor);
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends