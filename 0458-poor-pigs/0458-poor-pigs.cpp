class Solution {
public:
    int poorPigs(int N, int minutesToDie, int minutesToTest) {
        int x = 1;
        if (N == 1) return 0;
        int T = minutesToTest / minutesToDie;
        while (pow(T + 1, x) < N) x++;
        return x;
    }
};