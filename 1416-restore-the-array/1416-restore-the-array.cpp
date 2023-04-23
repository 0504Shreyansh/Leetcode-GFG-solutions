#define mod 1000000007
#define ll long long  
class Solution {
public:
    ll dp[100001];
    ll solve(string &s, ll k, int pos) {
        if(pos==s.length()) {
            return 1;
        }
        if(dp[pos]!=-1) {
            return dp[pos];
        }

        ll ans = 0, cur = 0;
        for(int i = pos; i < s.size(); i++) {
            cur = (cur * 10) + (s[i]-'0');
            if(cur <= k && cur >= 1ll) {
                ans = (ans + solve(s,k,i+1)) % mod;
            }
            else break;
        }
        return dp[pos] = ans;
    }
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(s, k, 0);   
    }
};