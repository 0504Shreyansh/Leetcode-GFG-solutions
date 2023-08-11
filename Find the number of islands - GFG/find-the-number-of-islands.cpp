//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visit) {
        visit[i][j] = 1;
        int n = grid.size(), m = grid[0].size();
        for (int k = 0; k < 8; k++) {
            int x = i + dirs[k].first, y = j + dirs[k].second;
            if (x >= 0 && x < n && y >= 0 && y < m && !visit[x][y] && grid[x][y] == '1') {
                dfs(x, y, grid, visit);
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visit(n, vector<bool> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visit[i][j]) {
                    ans++;
                    dfs(i, j, grid, visit);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends