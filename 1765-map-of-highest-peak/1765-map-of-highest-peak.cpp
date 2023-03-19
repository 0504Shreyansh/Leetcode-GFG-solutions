class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int N = isWater.size(), M = isWater[0].size();
        vector<vector<int>> peaks(N, vector<int> (M));
        vector<vector<int>> vis(N, vector<int>(M));
        queue<pair<int,int>> Q;
        
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (isWater[row][col] == 1) {
                    vis[row][col] = 1;
                    Q.push({row, col});
                }
            }
        }
        
        int newHeight = 1;
        while (Q.size()) {
            int size = Q.size();
            while (size--) {
                auto cur = Q.front();
                Q.pop();
                int i = cur.first, j = cur.second;
                for (auto [x, y] : dir) {
                    int X = x + i, Y = y + j;
                    if (X>=0 && X<N && Y>=0 && Y<M && !vis[X][Y]) {
                        peaks[X][Y] = newHeight;
                        vis[X][Y] = 1;
                        Q.push({X, Y});
                    }
                }
            }
            newHeight++;
        }
        
        return peaks;
    }
};