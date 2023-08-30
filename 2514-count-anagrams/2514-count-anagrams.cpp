class Solution {
private:
    const int mod = 1e9 + 7;
    long long power(long long a, long long b) {
        long long ans = 1;
        while (b) {
            if (b & 1) ans = (ans * a) % mod;
            b >>= 1;
            a = (a * a) % mod;
        }
        return ans;
    }
public:
    int countAnagrams(string s) {
        vector<long long> fact(100001, 1);
        for (int i = 1; i <= 100000; i++) {
            fact[i] = (i * fact[i - 1]) % mod;
        }
        stringstream ss(s);
        string word;
        long long res = 1;
        while (ss >> word) {
            unordered_map<char, int> mp;
            for (auto &j : word) {
                mp[j]++;
            }
            long long cur = fact[word.size()];
            for (auto &j : mp) {
                cur *= power(fact[j.second], mod - 2);
                cur %= mod;
            }
            res *= cur;
            res %= mod;
        }
        return res;
    }
};