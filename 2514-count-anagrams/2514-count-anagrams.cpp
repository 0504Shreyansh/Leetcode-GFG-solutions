class Solution {
public:
    const int mod = 1e9 + 7;
    #define ll long long
    ll fact[1000001];
    // Calculates the factorial of numbers up to 1e5
    void pre_compute() {
        fact[0] = fact[1] = 1;
        for(int i = 2; i < 1000001; i++)
            fact[i] = (i * fact[i - 1]) % mod;
    }
    // Calculates a^b in log(b) time
    ll binpow(ll a, ll b) {
        ll ans = 1;
        while(b) {
            if(b & 1)
                ans = (ans * a) % mod;
            b >>= 1;
            a = (a * a) % mod;
        }
        return ans;
    }
    int countAnagrams(string s) {
        pre_compute();
        stringstream ss(s);
        int ans = 1;
        while(ss >> s) {    // take out all the words
            unordered_map<char,int> freq;
            for(auto &it : s)
                freq[it]++;
            ll curr = fact[s.size()];
            for(auto &it : freq) {
                curr = (curr * binpow(fact[it.second], mod - 2)) % mod;
            }
            ans = (ans * curr) % mod;
            
        }
        return ans;
    }
};

/*
shreyansh --> 9! / (2! * 2!)    n = 9, repeat: s(2), h(2).

a / b % mod--> a * b^(-1) % mod--> a * b^(-1) % mod --> a * power(b, mod - 2)
*/