//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int t = 0, ones = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        queue<pair<int,int>> q;
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col]==2) {
                    visited[row][col] = 1;
                    q.push({row, col});
                }
                else if (grid[row][col])
                    ones++;
            }
        }
        int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
        
        while (q.size()) {
            int size = q.size();
            int removedOnes = 0;
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                int x = curr.first, y = curr.second;
                for (int index = 0; index < 4; index++) {
                    int new_row = x + dx[index], new_col = y + dy[index];
                    if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && !visited[new_row][new_col] && grid[new_row][new_col]) {
                        visited[new_row][new_col] = 1;
                        q.push({new_row, new_col});
                        removedOnes++;
                    }
                }
            }
            if (removedOnes) {
                ones -= removedOnes;
                t++;
            }
        }
        
        return (ones==0) ? t : -1;
        
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