class Solution {
private:
    int changes(string s) {
        int i = 0, j = s.size() - 1;
        int diff = 0;
        while(i < j) {
            if(s[i] != s[j]) diff++;
            i++, j--;
        }
        return diff;
    }

    int solve(int i, string &s, int k, vector<vector<int>>& dp) {
        if(i >= s.size()) {
            return 1e5;
        }
        if(k == 1) {
            return changes(s.substr(i, s.size() - i));
        }
        if(dp[i][k] != -1) return dp[i][k];
        string curr;
        int res = INT_MAX;
        for(int j = i; j < s.size(); ++j) {
            curr += s[j];
            int cur = changes(curr) + solve(j + 1, s, k - 1, dp);
            // cout << curr << ' ' << cur << endl; 
            res = min(res, cur);
        }
        return dp[i][k] = res;
    } 
    
public:
    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int> (k + 1, -1));
        return solve(0, s, k, dp);
    }
};