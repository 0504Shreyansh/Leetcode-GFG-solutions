class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //Store the freq of string s1
        unordered_map<char,int> mp;
        for(auto character:s1)
            mp[character]++;
        
        int i = 0, j = 0;
        int k = s1.size(), cnt = mp.size();
        
        while(j<s2.size()) {
            //Remove cnt of the jth character
            if(mp.find(s2[j])!=mp.end()) {
                mp[s2[j]]--;
                if(mp[s2[j]]==0) cnt--;
            }
            if(j-i+1==k) {
                if(cnt==0) 
                    return true;
                //Restore the cnt of the ith character before moving on
                if(mp.find(s2[i])!=mp.end()) {
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1) 
                        cnt++;
                }
                i++; 
            }
            j++;
        }
        return false;
    }
};