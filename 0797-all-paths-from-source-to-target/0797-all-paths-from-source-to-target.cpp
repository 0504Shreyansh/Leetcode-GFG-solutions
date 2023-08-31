class Solution {
private:
    void dfs(int u, int dest, vector<vector<int>>& graph, vector<int> t, vector<vector<int>>& res) {
        t.push_back(u);
        if (u == dest) {
            res.push_back(t);
            return ;
        }
        for (int &v : graph[u]) {    
            dfs(v, dest, graph, t, res);
        }
        t.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        vector<int> t;
        dfs(0, n - 1, graph, t, res);
        return res;
    }
};