class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        for (int i = 0; i < n / 7; i++) {
            ans += ((i + 7) * (i + 8)) / 2;
            ans -= (i * (i + 1)) / 2;
        }
        for (int i = 0; i < n % 7; i++) {
            ans += (n / 7) + 1 + i;
        }
        return ans;
    }
};