class Solution {
private:
    const int mod = 1e9 + 7;
    long long power(long long a, long long b) {
        long long ans = 1ll;
        while (b) {
            if (b & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
    unsigned long long solve(long long i, long long product, unsigned long long factor, map<int, int>& freq) {
        if (i > 30) return (product != 1) * factor;
        unsigned long long res = solve(i + 1, product, factor, freq);
        if ((i % 4 != 0) && (i % 9 != 0) && (i % 25 != 0) && __gcd(i, product) == 1) {
            res += (solve(i + 1, product * i, factor * 1ll * freq[i] % mod, freq)) % mod;
            res %= mod;
        }
        return res;
    }
    
public:
    int numberOfGoodSubsets(vector<int>& arr) {
        map<int, int> freq;
        for (auto &it : arr) {
            freq[it]++;
        }
        long long ans = (power(2, freq[1]) * solve(2, 1ll, 1ll, freq)) % mod;
        return (ans + mod) % mod;
    }
};