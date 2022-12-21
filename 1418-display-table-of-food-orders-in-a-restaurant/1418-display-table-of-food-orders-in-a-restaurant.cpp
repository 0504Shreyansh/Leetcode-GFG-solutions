class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        vector<vector<string>> ans;
        vector<string> t;
        t.push_back("Table");
        set<string> s;
        map<int,map<string,int>> mp;
        
        for(auto i:orders) {
            s.insert(i[2]);
            int tableNo = stoi(i[1]);
            string dish = i[2];
            mp[tableNo][dish]++;
        }
        
        for(auto i:s)
            t.push_back(i);
        ans.push_back(t);
        
        // for(auto i:t) cout<<i<<" "; cout<<endl;
        
        for(auto i:mp) {
            vector<string> temp;
            int n = t.size(), tableNo = i.first;
            // cout<<tableNo<<endl;
            temp.push_back(to_string(tableNo));
            for(int k=1;k<n;k++) {
                int cnt = mp[tableNo][t[k]];
                temp.push_back(to_string(cnt));
            }
    
            ans.push_back(temp);
        }
        
        // for(auto i:ans) {
        //     for(auto j:i) cout<<j<<" "; cout<<endl; 
        // }
        
        return ans;
        
    }
};