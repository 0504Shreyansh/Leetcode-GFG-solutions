class Solution {
public:
    int countOrders(int n) {
        const int mod = 1e9 + 7;
        long long ans = 1, prev = 1;
        for (long long i = 2; i <= n; i++) {
            ans = (prev * (2 * i - 1) * (i)) % mod;
            prev = ans;
        }
        return ans;
    }
};