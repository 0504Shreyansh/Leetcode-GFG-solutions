class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        int N = grid.size();
        int M = grid[0].size();
        
        // Edges cases
        if (grid[0][0]==1 && K==0) return -1;
        if (grid[0][0]==1) K--;
        
        // Required DS
        int dist = 0;
        vector<pair<int,int>> direction = 
            {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<vector<int>>> vis(N, 
            vector<vector<int>> (M, vector<int> (K+1, 0)));
        queue<pair<int,pair<int,int>>> Q;
        Q.push({K, {0, 0}});
        vis[0][0][K] = 1;
        // vis[i][j][k] -> cell (i, j) is reached with      
            // atmost k obstacles more can be removed further
        
        while (!Q.empty()) 
        {
            int size = Q.size();
            while (size--) 
            {
                auto cur = Q.front();
                Q.pop();
                int k = cur.first;
                int x = cur.second.first;
                int y = cur.second.second;
                if (x == N - 1 && y == M - 1)  // last cell 
                    return dist;
                for (auto [dx, dy] : direction)
                {
                    int newX = x + dx;
                    int newY = y + dy;
                    if (newX >= 0 && newX < N && newY >= 0 && newY < M) 
                    {
                        if (grid[newX][newY]==0 && !vis[newX][newY][k])
                        {
                            vis[newX][newY][k] = 1;
                            Q.push({k, {newX, newY}});
                        }
                        else if (grid[newX][newY]==1 && k > 0 && !vis[newX][newY][k-1])
                        {
                            vis[newX][newY][k-1] = 1;
                            Q.push({k-1, {newX, newY}});
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};