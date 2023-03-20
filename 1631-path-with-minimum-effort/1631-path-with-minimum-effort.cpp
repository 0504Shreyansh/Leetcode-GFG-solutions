class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int N = heights.size(), M = heights[0].size();
        vector<vector<int>> dist(N ,vector<int>(M, 1e9));
        dist[0][0] = 0;
        // Priority_queue + dijkstra
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        
        while (pq.size()) {
            auto cur = pq.top();
            pq.pop();
            int steps = cur.first;
            int curRow = cur.second.first;
            int curCol = cur.second.second;
            // cout<<steps<<' '<<curRow<<' '<<curCol<<endl;
            // Reached deastination with the minimum possible distance
            if (curRow==N-1 && curCol==M-1) 
                return steps;
            for (auto [x, y] : dir) {
                int newRow = curRow + x, newCol = curCol + y;
                if (newRow>=0 && newRow<N && newCol>=0 && newCol<M) {
                    int newWork = max(steps, abs(heights[newRow][newCol] - heights[curRow][curCol]));
                    if (newWork < dist[newRow][newCol]) {
                        dist[newRow][newCol] = newWork;
                        pq.push({newWork, {newRow, newCol}});
                    }
                }
            }  
        }
        return 0;
    }
};