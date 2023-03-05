class Solution {
public:
    // #define minHeapString <string,vector<string>,greater<string>>
    vector<string> ans;
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
    void dfs(string s) {
        auto &x = adj[s];
        while(x.size()) {
            string to = x.top();
            x.pop();
            dfs(to);
        }
        // cout<<s<<endl;
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto e: tickets) 
            adj[e[0]].push(e[1]);
        
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};