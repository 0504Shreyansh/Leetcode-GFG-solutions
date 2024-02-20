class Solution {
public:
    int missingNumber(vector<int>& A) {
        int XOR = 0, n = A.size();
        for (int i = 1; i <= n; i++) {
            XOR ^= i;
            XOR ^= A[i - 1];
        }
        return XOR;
    }
};