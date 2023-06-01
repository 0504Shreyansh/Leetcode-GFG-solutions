class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        if(grid[0][0] == 1) return -1;
        vector<vector<bool>> vis(N, vector<bool> (M, 0));
        vector<pair<int,int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}};
        queue<pair<int,int>> Q({{0, 0}});
        vis[0][0] = true;
        int steps = 1;
        while(!Q.empty()) {
            int size = Q.size();
            for(int i = 0; i < size; i++) {
                auto curr = Q.front();
                Q.pop();
                int x = curr.first;
                int y = curr.second;
                if(x == N - 1 && y == M - 1) {
                    return steps;
                }
                for(auto [dx, dy] : direction) {
                    int newX = x + dx;
                    int newY = y + dy;
                    if(newX >= 0 && newX < N && newY >= 0 && newY < M && !vis[newX][newY] && grid[newX][newY]==0) {
                        vis[newX][newY] = true;
                        Q.push({newX, newY});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};