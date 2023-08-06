class Solution {
private:
    void dfs(string node, unordered_map<string, vector<string>>& graph, set<pair<string, int>>& seen, stack<string>& st) {
        for (int i = 0; i < graph[node].size(); i++) {
            if (seen.count({node, i})) 
                continue;
            seen.insert({node, i});
            dfs(graph[node][i], graph, seen, st);
        }
        st.push(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        for (auto &it : tickets) {
            graph[it[0]].push_back(it[1]);
        }
        for (auto &it : graph) sort(begin(it.second),end(it.second));
        set<pair<string, int>> seen;
        stack<string> st;
        dfs("JFK", graph, seen, st);
        vector<string> ans;
        while (st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};