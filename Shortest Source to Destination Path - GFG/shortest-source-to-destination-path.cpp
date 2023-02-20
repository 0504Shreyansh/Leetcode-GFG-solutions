//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y) {
        
        if(!A[0][0])
            return -1;
        
        queue<pair<int,int>> q({{0, 0}});
        int steps = 0;
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vector<vector<int>> vis(n, vector<int> (m));
        vis[0][0] = 1;
        
        while(q.size()) {
            int x = q.size();
            for(int i = 0; i < x; i++) {
                auto cur = q.front();
                q.pop();
                int curRow = cur.first, curCol = cur.second;
                if(curRow==X && curCol==Y)
                    return steps;
                for(int k = 0; k < 4; k++) {
                    int newRow = curRow + dir[k].first, newCol = curCol + dir[k].second;
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && A[newRow][newCol] && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
            steps++;
        }
        return -1  ;      
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends