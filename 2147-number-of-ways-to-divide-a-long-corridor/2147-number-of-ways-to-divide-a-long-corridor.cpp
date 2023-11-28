class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1e9 + 7;
        long long ans = 1;
        int count = 0, plants = 0;
        for (auto &c : corridor) {
            if (c == 'S') {
                if (count == 2) {
                    ans *= (plants + 1);
                    ans %= mod;
                    plants = 0;
                    count = 0;
                }
                count++;
            } else {
                if (count == 2) {
                    plants++;
                }
            }
        }
        if (count <= 1 && plants == 0)
            ans = 0;
        return ans;
    }
};