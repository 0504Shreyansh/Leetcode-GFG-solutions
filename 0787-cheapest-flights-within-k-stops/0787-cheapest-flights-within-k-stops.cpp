class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        k++;
        while (k--) {
            vector<int> temp(dist);
            for (auto &it : flights) {
                int u = it[0], v = it[1], w = it[2];
                if (dist[u] != 1e9 && temp[v] > dist[u] + w) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};