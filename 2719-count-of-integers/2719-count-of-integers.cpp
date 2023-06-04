class Solution {
public:
    const int mod = 1e9 + 7;
    int build(string &s, int curIndex, int n, int sum, bool tight, vector<vector<vector<int>>> &dp) {
        // Base case
        if (n == 0) {
            return (sum == 0) ? 1 : 0;
        }

        if (dp[n][sum][tight] != -1) {
            return dp[n][sum][tight] % mod;
        }
        
        int answer = 0;
        
        char upperLimit = (tight) ? s[curIndex] : '9';

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
        return dp[n][sum][tight] = answer % mod;
    }

    void decreaseBy1(string &str) {
        int n = str.size();
        int i = n - 1;
        while (i >= 0 && str[i] == '0') 
            str[i--] = '9';
        str[i] = str[i] - 1;
    }

    int count(string num1, string num2, int sum1, int sum2) {
        
        int n = num1.size();
        int m = num2.size();
        decreaseBy1(num1);
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(221, vector<int>(2, -1)));
        vector<vector<vector<int>>> dp2(m + 1, vector<vector<int>> (221, vector<int> (2, -1)));

        int ans1 = 0;
        for (int sum = sum1; sum <= min(220, sum2); sum++) {
            ans1 = (ans1 + build(num1, 0, n, sum, true, dp)) % mod;
        }
        int ans2 = 0;
        for (int sum = sum1; sum <= min(220, sum2); sum++) {
            ans2 = (ans2 + build(num2, 0, m, sum, true, dp2)) % mod;
        }

        return ((ans2 - ans1) % mod + mod) % mod;
    }
};