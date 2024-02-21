class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        bitset<32> b1(left), b2(right), b3(0);
        for (int i = 31; i >= 0; i--) {
            if (b1[i] == b2[i]) b3[i] = b1[i];
            else break;
        }
        return b3.to_ulong();
    }
};