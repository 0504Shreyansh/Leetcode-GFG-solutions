class Solution {
private:
    void dfs(string u, unordered_map<string, vector<string>>& G, map<pair<string, int>, bool>& visit, stack<string>& st) {
        for (int i = 0; i < G[u].size(); i++) {
            if (!visit[{u, i}]) {
                visit[{u, i}] = 1;
                dfs(G[u][i], G, visit, st);
            }
        } 
        st.push(u);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> G;
        for (auto &it : tickets) 
            G[it[0]].push_back(it[1]);
        for (auto &it : G) 
            sort(begin(it.second), end(it.second));
        
        map<pair<string, int>, bool> visit;
        stack<string> st;
        dfs("JFK", G, visit, st);
        vector<string> answer;
        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }
        return answer;
    }
};