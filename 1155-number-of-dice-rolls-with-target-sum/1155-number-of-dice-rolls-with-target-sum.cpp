#define mod 1000000007
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> prev(target + 1);
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> curr(target + 1);
            for (int j = 0; j <= target; j++) {
                for (int x = 1; x <= k && j - x >= 0; x++) {
                    curr[j] = (curr[j] + prev[j - x]) % mod;
                }
            }
            prev = curr;
        }
        return prev[target];  
    }
};