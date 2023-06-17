class Solution {
public:
    string findLCS(string &str1, string &str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];  
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }        
        string lcs;
        int i = n, j = m;
        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                lcs += str1[i - 1];
                i--, j--;
            }
            else if(dp[i - 1][j] == dp[i][j]) {
                i--;
            }
            else {
                j--;
            }
        }
        reverse(begin(lcs),end(lcs));
        return lcs;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string lcs = findLCS(str1, str2);
        int i = 0, j = 0, k = 0;
        string superString;
        while(i < n && j < m && k < lcs.size()) {
            while(str1[i] != lcs[k]) 
                superString += str1[i++];
            while(str2[j] != lcs[k])
                superString += str2[j++];
            superString += lcs[k];
            i++, j++, k++;
        }
        return superString + str1.substr(i) + str2.substr(j);
    }
};