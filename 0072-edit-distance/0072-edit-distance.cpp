class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        for(int i = 0; i <= n; i++)  {
            for(int j = 0; j <= m; j++)  {
                if(!i) dp[i][j] = j;
                if(!j) dp[i][j] = i;
            }
        }
        
        for(int i = 1; i <= n; i++)  {
            for(int j = 1; j <= m; j++)  {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]); 
            }
        }
        // for(auto i: dp) {
        //     for(auto j:i) cout<<j<<' '; cout<<endl;
        // }
        
        return dp[n][m];
    }
};