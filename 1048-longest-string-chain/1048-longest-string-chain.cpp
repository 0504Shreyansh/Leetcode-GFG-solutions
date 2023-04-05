class Solution {
public:
    bool isValidChain(string s1, string s2) {
        int i = 0, j = 0;
        int change = 0;
        if(s1.size() != s2.size()+1) return false;
        while(i < s1.size() && j < s2.size()) {
            if(s1[i] == s2[j])
                i++, j++;
            else 
                change++, i++;
        }
        if(change==1) return true;
        if(change==0 && i!=s1.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(begin(words),end(words),[&](string &s1, string &s2) {
            return s1.size() < s2.size();
        });
        int n = words.size();
        int ans = 1;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(isValidChain(words[i], words[j])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        return ans;
    }
};