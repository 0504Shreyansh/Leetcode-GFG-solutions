//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visit(n, vector<int> (m));
        int oranges = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visit[i][j] = 1;
                } else if (grid[i][j] == 1) {
                    oranges++;
                }
            }
        }
        int dirs[] = {0, -1, 0, 1, 0};
        int steps = 0;
        while (q.size()) {
            int size = q.size();
            if (oranges == 0) {
                return steps;
            }
            while (size--) {
                auto cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;
                for (int k = 0; k < 4; k++) {
                    int X = x + dirs[k], Y = y + dirs[k + 1];
                    if (X >= 0 && X < n && Y >= 0 && Y < m && !visit[X][Y] && grid[X][Y] == 1) {
                        oranges--;
                        q.push({X, Y});
                        visit[X][Y] = 1;
                    }
                }
            }
            steps++;
        }
        if (oranges == 0) return 0;
        return -1;
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