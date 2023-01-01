class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        s += ' ';
        vector<string> v;
        set<string> ss;
        set<char> sss;
        string temp;
        for(int i=0;i<s.size();i++) {
            if(s[i]!=' ')
                temp += s[i];
            else{
                v.push_back(temp);
                ss.insert(temp);
                temp.clear();
            }
        }
        for(auto i:pattern) sss.insert(i);
        
        unordered_map<char,string> mp;
        
        if(pattern.size()!=v.size() || ss.size()!=sss.size())
            return false;
        for(int i=0;i<pattern.size();i++) {
            if(mp.find(pattern[i])!=mp.end()) {
                if(mp[pattern[i]]!=v[i]) 
                    return false;
            }
            else 
                mp[pattern[i]] = v[i];
            // cout<<pattern[i]<<' '<<v[i]<<endl;
        }
        
        return true;
        
        
    }
};