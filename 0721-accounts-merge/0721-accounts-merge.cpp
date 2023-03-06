class Solution {
public:
    void dfs(string node, unordered_map<string,vector<string>> &mp, unordered_map<string,int>& mpp, vector<string> &v) {
        mpp[node]++;
        v.push_back(node);
        for(auto i : mp[node]) 
            if(!mpp[i])
                dfs(i, mp, mpp, v);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string,vector<string>> mp;
        unordered_map<string,string> name;
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size()-1; j++) {
                mp[accounts[i][j]].push_back(accounts[i][j+1]);
                mp[accounts[i][j+1]].push_back(accounts[i][j]);
                name[accounts[i][j]] = accounts[i][0];
                name[accounts[i][j+1]] = accounts[i][0];
            }
            if(accounts[i].size()==2) {
                name[accounts[i][1]] = accounts[i][0];
                mp[accounts[i][1]].push_back("");
            }
        }
        
        // for(auto i: name) {
        //     cout<<i.first<<' '<<i.second<<endl;
        // }
        
        unordered_map<string,int> mpp;
        mpp[""]++;
        vector<vector<string>> ans;
        
        for(auto i: mp) {
            string node = i.first;
            vector<string> v;
            if(!mpp[node]) {
                dfs(node, mp, mpp, v);
            }
            if(v.size()) {
                sort(v.begin(),v.end());
                reverse(v.begin(),v.end());
                v.push_back(name[v[0]]);
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            // for(auto j : i.second) {
            //     vector<string> v;
            //     if(!mpp[j]) {
            //         dfs(j, mp, mpp, v);
            //     }
            //     if(v.size()) {
            //         v.push_back(name[v.back()]);
            //         sort(v.begin(),v.end());
            //         ans.push_back(v);
            //     }
            // }
        }
        
        return ans;
    }
};