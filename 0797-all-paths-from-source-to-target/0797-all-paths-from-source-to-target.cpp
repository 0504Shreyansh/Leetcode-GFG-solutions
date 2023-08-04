class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int source, int dest, vector<vector<int>>& graph, vector<int> cur) {
        cur.push_back(source);
        if (source == dest) {
            ans.push_back(cur);
            return ;
        }
        for (auto &it : graph[source]) {
            dfs(it, dest, graph, cur);
        }
        cur.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> cur;
        dfs(0, graph.size() - 1, graph, cur);
        return ans;
    }
};