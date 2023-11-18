class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int i, res = 0, n = A.size();
        long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += A[j];
            while (sum + k < (1LL) * (j - i + 1) * A[j])
                sum -= A[i++];
            res = max(res, j - i + 1);
        }
        return res;
    }
};