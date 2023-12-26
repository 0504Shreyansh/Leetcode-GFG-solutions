class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int mod = 1e9 + 7;
        vector<int> prev(target + 1);
        prev[0] = 1;
        for (int i = 1; i <= n; i++) {
            vector<int> curr(target + 1);
            for (int j = 0; j <= target; j++) {
                for (int t = 1; t <= k; t++) {
                    if (j >= t) {
                        curr[j] = (curr[j] + prev[j - t]) % mod;
                    }
                }
            }
            prev = curr;
        }
        return prev[target];
    }
};