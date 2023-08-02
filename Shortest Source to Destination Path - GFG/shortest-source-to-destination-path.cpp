//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<int>> vis(N, vector<int> (M));
        if (A[0][0] == 0 || A[X][Y] == 0) return -1;
        queue<pair<int, int>> Q({{0, 0}});
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vis[0][0] = 1;
        int steps = 0;
        while (Q.size()) {
            int size = Q.size();
            while (size--) {
                auto cur = Q.front();
                Q.pop();
                int x = cur.first;
                int y = cur.second;
                if (x == X && y == Y) return steps;
                for (auto v : dir) {
                    int newX = x + v.first;
                    int newY = y + v.second;
                    if (newX >= 0 && newX < N && newY >= 0 && newY < M && !vis[newX][newY] && A[newX][newY]) {
                        vis[newX][newY] = 1;
                        Q.push({newX, newY});
                    }
                }
            }
            steps++;
        }
        return -1;
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