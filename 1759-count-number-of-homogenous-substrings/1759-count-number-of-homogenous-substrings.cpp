#define mod 1000000007
#define ll long long
class Solution {
public:
    int countHomogenous(string s) {
        ll ans = 0;
        int j = 0, n = s.size();
        for(int i = 0; i < s.size(); i++) {
            while(j + 1 < n && s[i] == s[j + 1]) j++;
            ll len = j - i + 1;
            ans = (ans + (len * (len + 1)) / 2) % mod;
            i = j;
        }
        return ans;
    }
};