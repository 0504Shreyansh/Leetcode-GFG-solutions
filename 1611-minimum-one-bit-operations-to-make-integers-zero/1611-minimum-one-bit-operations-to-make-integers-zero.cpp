class Solution {
public:
    int minimumOneBitOperations(int n) {
        // The base case of recursion: 0 and 1
        if (n <= 1) {
            return n;
        }
        // Now we find the next bit of the highest set bit
        int msb = 0;
        while ((1 << msb) <= n) {
            msb++;
        }
        return ((1 << msb) - 1) - minimumOneBitOperations(n - (1 << (msb - 1)));
    }
};