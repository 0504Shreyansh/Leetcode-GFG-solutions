class Solution {
private:
    const int mod = 1e9 + 7;
    #define LL long long
    LL power(LL a, LL b) {
        LL ans = 1;
        while (b) {
            if (b & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans % mod;
    }
    LL solve(int i, int mask, int n, vector<int>& nums, vector<int>& masks, vector<int>& cnt, vector<vector<LL>>& dp) {
        if (i > 30) return 1;
        if (dp[i][mask] != -1) return dp[i][mask];
        int ans = solve(i + 1, mask, n, nums, masks, cnt, dp);
        int newMask = masks[i];
        if (newMask != 0 && (newMask ^ mask) == (mask + newMask)) {
            ans = (ans + cnt[i] * solve(i + 1, mask | newMask, n, nums, masks, cnt, dp)) % mod;
        }
        return dp[i][mask] = ans;
    }
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        map<int, int> mp;
        int idx = 0;
        for (auto &p : primes) {
            mp[p] = idx++;
        }
        
        int n = nums.size(), ones = 0;
        vector<int> cnt(31);
        for (int &num : nums) {
            if (num == 1) ones++;
            else if (num % 4 == 0 || num % 9 == 0 || num == 25) continue;
            else {
                cnt[num]++;
            }
        }
        
        vector<int> masks(31);
        for (int i = 2; i <= 30; i++) {
            if (cnt[i] == 0) continue;
            int num = i;
            for (int j = 2; j * j <= num; j++) {
                while (num % j == 0) {
                    masks[i] |= (1 << mp[j]);
                    num /= j;
                }
            }
            if (num > 1) masks[i] |= (1 << mp[num]);
        }
        
        vector<vector<LL>> dp(31, vector<LL> (1024, -1));
        LL ans = 0;
        for (int i = 2; i <= 30; i++) {
            if (cnt[i]) {
                ans = (ans + cnt[i] * solve(i + 1, masks[i], n, nums, masks, cnt, dp)) % mod;
            }
        }
        
        ans = (ans * power(2, ones)) % mod;
        return ans;
    }
};