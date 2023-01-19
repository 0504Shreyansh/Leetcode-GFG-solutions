class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size() < t.size())
            return "";
        
        int i = 0, j = 0, ind = -1, size = INT_MAX;
        map<char,int> mp;
        for(auto x:t)
            mp[x]++;
        int cnt = mp.size();
        while(j < s.size()) {
            
            mp[s[j]]--;
            if(mp[s[j]]==0)
                cnt--;
            
            while(!cnt) {
                if(j-i+1<size) {
                    size = j-i+1;
                    ind = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                    cnt++;
                i++;
                    
            }
            j++;
            // cout<<i<<' '<<j<<endl;
        }
        
        return (size==INT_MAX) ? "":s.substr(ind,size);
        
    }
};