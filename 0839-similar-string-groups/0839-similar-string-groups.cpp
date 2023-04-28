class Solution {
public:
    vector<int> parent;
    int findParent(int node) {
        return (node==parent[node]) ? node : parent[node] = findParent(parent[node]);
    }
    bool isSimilar(string s1, string s2) {
        int change = 0;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) 
                change++;
        }
        return (change==0 || change==2);
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        for(int i = 0; i < n; i++) parent.push_back(i);
        int cntGroups = n;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(isSimilar(strs[i], strs[j])) {
                    int up = findParent(i);
                    int vp = findParent(j);
                    if(up != vp)
                        parent[vp] = up, cntGroups--;
                }
            }
        } 
        return cntGroups;
    }
};