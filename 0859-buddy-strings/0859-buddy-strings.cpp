class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // edge cases
        if(s.size() != goal.size() || (s.size() == 1 && goal.size() == 1)) {
            return false;
        }
        int n = s.size();
        map<char, int> mp;
        for(int i = 0; i < n; i++) {
            if(++mp[s[i]] == 0) mp.erase(s[i]);
            if(--mp[goal[i]] == 0) mp.erase(goal[i]);
        }
        // some different chars
        if(mp.size() != 0) return false;
        
        int idx1 = -1, idx2 = -1;
        char c1, c2;
        for(int i = 0; i < n; i++) {
            if(s[i] != goal[i]) {
                if(idx1 == -1) {
                    idx1 = i, c1 = s[i], c2 = goal[i];
                } else if(idx2 == -1) {
                    idx2 = i;
                    if(c1 == goal[i] && c2 == s[i]) {
                        continue;
                    }
                } else {
                    return false;
                }
            }
        }
        set<char> s1(begin(s),end(s));
        set<char> s2(begin(goal),end(goal));
        
        // same set of chars
        if(s1.size() == s2.size()) {
            if(s1.size() == 1) {   // all chars are same
                if(*s1.begin() == *s2.begin()) return true;
                return false;  
            } else if(n != s1.size()) {   
                return true;
            }
        } 
        if(s == goal) return false;
        // if(idx1 == -1 && idx2 == -1) return false;
        // if(idx2 == -1) return false;
        return true;
    }
};