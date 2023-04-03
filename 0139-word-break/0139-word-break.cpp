class Solution {
public:
    unordered_map<string,int> mp;
    bool solve(int i, string &A, string cur, vector<int>& dp) {
        if(i >= A.size()) {
            return (cur.size()==0) ? true : false;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        for(int j = i; j < A.size(); j++) {
            if(mp.count(A.substr(i, j + 1 - i)) && solve(j+1, A, "", dp)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word : wordDict)
            mp[word]++;
        vector<int> dp(s.size()+1, -1);
        return solve(0, s, "", dp);
    }
};