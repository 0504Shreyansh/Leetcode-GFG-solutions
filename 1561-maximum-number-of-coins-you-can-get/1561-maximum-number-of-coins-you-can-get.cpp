class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(rbegin(piles), rend(piles));
        int i = 0, res = 0, n = piles.size();
        while ((2 * i + 1) < (2 * n) / 3) {
            res += piles[2 * i + 1];
            i++;
        }
        return res;
    }
};