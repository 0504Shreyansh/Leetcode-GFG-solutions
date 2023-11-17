class Solution {
public:
    int minPairSum(vector<int>& A) {
        sort(begin(A), end(A));
        int n = A.size(), res = -1;
        for (int i = 0; i < n / 2; ++i) 
            res = max(res, A[i] + A[n - 1 - i]);
        return res;
    }
};