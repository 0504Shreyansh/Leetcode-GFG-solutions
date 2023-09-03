class Solution {
public:
    int uniquePaths(int m, int n) {
        long double res = 1.0;
        int r = m - 1;
        for (int i = 1; i <= r; ++i) {
            res *= (n + r - i);
            res /= i;
        }
        return res;
    }
};