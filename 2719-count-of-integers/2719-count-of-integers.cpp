#define ll long long
#define mod 1000000007
class Solution {
public:
    ll build(string &s, int curIndex, int n, int sum, bool tight, vector<vector<vector<ll>>> &dp)
    {
        // Base case
        if (n == 0) {
            return (sum == 0) ?1ll : 0;
        }

        if (dp[n][sum][tight] != -1) {
            return dp[n][sum][tight] % mod;
        }
        
        ll answer = 0;
        
        char upperLimit = (tight) ? s[curIndex] : '9';
        // if (tight) {
            for (char ch = '0'; ch <= upperLimit; ch++) {
                if (ch == s[curIndex] && tight) {
                    if (sum >= (ch - '0')) { // more tight conditions
                        answer = (answer + build(s, curIndex + 1, n - 1, sum - (ch - '0'), tight, dp)) % mod;
                    }
                }
                else { // remove the tight from here
                    if (sum >= (ch - '0')) {
                        answer = (answer + build(s, curIndex + 1, n - 1, sum - (ch - '0'), false, dp)) % mod;
                    }
                }
            }
        // }
        // else {
        //     for (char ch = '0'; ch <= '9'; ch++) {
        //         if (sum >= (ch - '0')) { // build freely
        //             answer = (answer + build(s, curIndex + 1, n - 1, sum - (ch - '0'), false, dp)) % mod;
        //         }
        //     }
        // }
        return dp[n][sum][tight] = answer % mod;
    }

    void decreaseBy1(string &str)
    {
        int n = str.size();
        int i = n - 1;
        while (i >= 0 && str[i] == '0')
        {
            str[i] = '9';
            i--;
        }
        str[i] = str[i] - 1;
    }

    int count(string num1, string num2, int sum1, int sum2) {
        decreaseBy1(num1);
        vector<vector<vector<ll>>> dp(23, vector<vector<ll>>(250, vector<ll>(2, -1)));
        vector<vector<vector<ll>>> dp2(23, vector<vector<ll>> (250, vector<ll> (2, -1)));

        int ans1 = 0;
        for (int sum = sum1; sum <= min(220, sum2); sum++) {
            ans1 = (ans1 + build(num1, 0, num1.size(), sum, true, dp)) % mod;
        }
        int ans2 = 0;
        for (int sum = sum1; sum <= min(220, sum2); sum++) {
            ans2 = (ans2 + build(num2, 0, num2.size(), sum, true, dp2)) % mod;
        }

        return ((ans2 - ans1) % mod + mod) % mod;
    }
};