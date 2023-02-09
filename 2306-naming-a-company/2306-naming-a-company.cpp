class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        unordered_set<string> st(ideas.begin(), ideas.end());
        long long n = ideas.size(), ans = 0;
        long long dp[26][26] = {0};
        
        for (int i = 0; i < n; i++) {
            string word = ideas[i];
            char org = word[0];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[0] = ch;
                if(st.find(word)==st.end()) 
                    dp[org-'a'][ch-'a']++;
                
            }
        }
        
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) 
                ans += dp[i][j]*dp[j][i];
        }
        
        return ans;
    }
};