class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> graph;
        int n = routes.size();
        for (int i = 0; i < n; ++i) {
            for (int &stop : routes[i]) {
                graph[stop].push_back(i);
            }
        }
        
        unordered_set<int> seen_route;
        queue<int> q({source});
        int route_count = 0; 
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int bus = q.front();
                q.pop();
                if (bus == target) 
                    return route_count;
                for (int &route : graph[bus]) {
                    if (seen_route.find(route) != seen_route.end())
                        continue;
                    seen_route.insert(route);
                    for (int &currBus : routes[route]) {
                        q.push(currBus);
                    }
                }
            }
            route_count++;
        }
        return -1;
    }
};