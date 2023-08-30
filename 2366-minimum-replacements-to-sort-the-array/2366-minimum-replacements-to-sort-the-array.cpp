class Solution {
public:
    long long minimumReplacement(vector<int>& A) {
        int n = A.size();
        long long res = 0;
        int prev = A.back();
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > prev) {
                int cur = ((A[i] - 1) / prev);
                res += cur;
                prev = A[i] / (cur + 1);
            } else {
                prev = A[i];
            }
        }
        return res;
    }
};