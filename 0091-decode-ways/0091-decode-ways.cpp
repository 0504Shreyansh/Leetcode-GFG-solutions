#define mod 1000000007
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        if(s[0]=='0')
            return 0;
        dp[0] = 1, dp[1] = 1;

        for(int i = 1; i < n; i++) {
            // Check for non-zero char
            if(s[i]!='0')
                dp[i+1] += dp[i];
            string x = "";
            x += s[i-1];
            x += s[i];
            // Check if combined with prev char will give a valid no.
            if(x<="26" && s[i-1]!='0')
                dp[i+1] += dp[i-1];
        }
        return dp[n];
    }
};