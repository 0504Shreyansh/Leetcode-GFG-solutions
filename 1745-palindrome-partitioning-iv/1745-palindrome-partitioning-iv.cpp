class Solution {
public:
    bool isPalindrome(string& s, int i, int j, vector<vector<int>>& dp) {
		if (i >= j) return true;
		if (dp[i][j] != -1) return dp[i][j];
		if (s[i] == s[j]) return dp[i][j] = isPalindrome(s, i + 1, j - 1, dp);
		return dp[i][j] = false;
	}

    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n-1; j++) {
                if(isPalindrome(s, 0, i, dp) 
                   && isPalindrome(s, i+1, j, dp) 
                   && isPalindrome(s, j+1, n-1, dp))
                    return true;
            }
        }
        return false;
    }
};