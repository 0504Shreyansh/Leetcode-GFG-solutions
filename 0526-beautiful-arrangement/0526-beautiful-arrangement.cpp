class Solution {
private:
    int solve(int i, int mask, int n) {
        if (i > n) return (mask == (1 << n) - 1);
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if (mask & (1 << (j - 1))) continue;
            if (i % j == 0 || j % i == 0) {
                ans += solve(i + 1, mask | (1 << (j - 1)), n);
            }
        }
        return ans;
    }
public:
    int countArrangement(int n) {
        return solve(1, 0, n);
    }
};