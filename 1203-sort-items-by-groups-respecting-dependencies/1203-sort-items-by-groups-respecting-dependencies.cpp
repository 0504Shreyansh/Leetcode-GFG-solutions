class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        // graph of groups
        int groupId = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = groupId++;
            }
        } 
                
        // graph of items
        vector<int> items[n];
        vector<int> indegree(n);
        vector<int> top[groupId];
        vector<int> indegreeTop(groupId);
        for (int i = 0; i < beforeItems.size(); i++) {
            for (auto &before : beforeItems[i]) {
                items[before].push_back(i);
                indegree[i]++;
                if (group[before] != group[i]) {
                    top[group[before]].push_back(group[i]);
                    indegreeTop[group[i]]++;
                } 
            }
        }
        
        // topological sort for items
        vector<vector<int>> itemGroup(groupId);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            itemGroup[group[u]].push_back(u);
            for (int &v : items[u]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // topological sort for groups
        vector<int> Group;
        for (int i = 0; i < groupId; i++) {
            if (indegreeTop[i] == 0) {
                q.push(i);
            }
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            Group.push_back(u);
            for (int &v : top[u]) {
                if (--indegreeTop[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        vector<int> ans;
        for (auto &j : Group) {
            for (auto &it : itemGroup[j]) {
                ans.push_back(it);
            }
        }
        if (ans.size() != n) ans.clear();
        return ans;
    }
};