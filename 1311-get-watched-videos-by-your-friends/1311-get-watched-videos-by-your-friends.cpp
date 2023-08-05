class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& videos, vector<vector<int>>& graph, int id, int level) {
        int n = graph.size();
        vector<int> vis(n, 0);
        queue<int> Q({id});
        vis[id] = 1;
        vector<int> friends({id});
        for (int i = 0; i <= level; i++) {
            int size = Q.size();
            if (size != 0) friends.clear();
            while (size--) {
                int u = Q.front();
                Q.pop();
                friends.push_back(u);
                for (auto &v : graph[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        Q.push(v);    
                    }
                }
            }
        }
        map<string, int> vids;
        for (auto &f : friends) {
            for (auto &video : videos[f]) {
                vids[video]++;
            } 
        }
        vector<pair<int, string>> pairs;
        for (auto &it : vids) {
            pairs.push_back({it.second, it.first});
        }
        sort(begin(pairs),end(pairs));
        vector<string> ans;
        for (auto &it : pairs) {
            ans.push_back(it.second);
        }
        return ans;
    }
};