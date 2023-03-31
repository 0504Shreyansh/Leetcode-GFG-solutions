class Solution {
public:
    bool allStars(string s, int i) {
        // Checks whether only stars are present or not
        for(int k = 0; k <= i; k++)
            if(s[k] != '*')
                return false;
        return true;
    }
    int recSol(int i, int j, string &pattern, string &str) {
        
        // Both the strings are exhausted simultaneously
        // i.e. they have been completely matched.
        if(i<0 && j<0) 
            return true;
        
        // Pattern string is exhausted but 
        // second string remains, so return false
        if(i<0 && j>=0)
            return false;
        
        // Only possible case of matching in case of string exhaustion
        // Pattern string contains all stars!
        if(i>=0 && j<0)
            return allStars(pattern, i);
        
        // If the chars match just reduce both the indices by 1 
        if(pattern[i] == str[j] || pattern[i] == '?')
            return recSol(i-1, j-1, pattern, str);
        
        // Either don't consider inplace of '*'
        // Or consider a character
        if(pattern[i] == '*')
            return recSol(i-1, j, pattern, str) | recSol(i, j-1, pattern, str);
        
        // No matching possible :(
        return false;
    }
    bool isMatch(string str, string pattern) {
        
        int n = pattern.size(), m = str.size();
        
        if(n==0 && m==0)
            return true;
        
        vector<bool> cur(m+1, false), prev(m+1, false);
        // return recSol(n-1, m-1, pattern, str);
        // Base case 
        prev[0] = true;
        
        for(int i = 1; i <= n; i++) {
            cur[0] = allStars(pattern, i-1);
            for(int j = 1; j <= m; j++) {
                
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
                    cur[j] = prev[j-1];
                
                else if(pattern[i-1] == '*')
                    cur[j] = prev[j] | cur[j-1];
                
                else 
                    cur[j] = false;
            }
            
            prev = cur;
        }
        
        return cur[m];
    }
};