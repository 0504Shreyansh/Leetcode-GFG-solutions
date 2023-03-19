class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int N = maze.size(), M = maze[0].size();
        int sr = entrance[0], sc = entrance[1];
        queue<pair<int,int>> Q({{sr, sc}});
        vector<vector<int>> vis(N, vector<int> (M, 0));
        vis[sr][sc] = 1;
        int steps = 0;
        
        while (Q.size()) {
            int size = Q.size();
            while (size--) {
                auto cur = Q.front();
                Q.pop();
                int i = cur.first, j = cur.second;
                if ((i==0 || j==0 || i==N-1 || j==M-1) && (i!=sr||j!=sc))
                    return steps;
                for (auto [x, y] : dir) {
                    int X = i + x, Y = j + y;
                    if (X>=0 && X<N && Y>=0 && Y<M && !vis[X][Y] && maze[X][Y]=='.') {
                        vis[X][Y] = 1;
                        Q.push({X, Y});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};