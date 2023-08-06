class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> present(begin(supplies),end(supplies));
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = 0;
            for (auto &it : ingredients[i]) {
                graph[it].push_back(recipes[i]);
                if (!present.count(it)) {
                    indegree[recipes[i]]++;
                }
            }
        }
        queue<string> Q;
        for (auto &it : indegree) {
            if (it.second == 0) {
                Q.push(it.first);
            }
        }
        vector<string> ans;
        while (Q.size()) {
            int size = Q.size();
            while (size--) {
                string u = Q.front();
                Q.pop();
                ans.push_back(u);
                for (auto &v : graph[u]) {
                    if (--indegree[v] == 0) {
                        present.insert(v);
                        Q.push(v);
                    }
                }
            }
        }
        return ans;
    }
};