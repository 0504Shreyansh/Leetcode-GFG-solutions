class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 1;
        int L = 1;
        while ((L * (L + 1)) < 2 * n) {
            double a = (1.0 * (n - (L * (L + 1)) / 2)) / (L + 1);
            if (a - (int)a == 0.0) res++;
            L++;
        }
        return res;
    }
};