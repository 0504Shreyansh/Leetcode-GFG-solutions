class Solution {
public:
    bool validPartition(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, false);
        dp[n] = true;
        bool S2 = 0, S3 = 1;
        bool S1 = (A[n - 1] == A[n - 2]);
        if (n == 2) return S1;
        bool S0 = (A[n - 1] == A[n - 2] && A[n - 2] == A[n - 3])
            || (A[n - 1] - 1 == A[n - 2] && A[n - 2] - 1 == A[n - 3]);
        if (n == 3) return S0;
        for (int i = n - 3; i >= 0; i--) {
            if (A[i] == A[i + 1]) 
                S0 |= S2;
            if (A[i] == A[i + 1] && A[i] == A[i + 2]) 
                S0 |= S3;
            if (A[i + 1] - A[i] == 1 && A[i + 2] - A[i + 1] == 1)
                S0 |= S3;
            S3 = S2;
            S2 = S1;
            S1 = S0;
            S0 = 0;
            // cout << S0 << ' ' << S1 << ' ' << S2 << ' ' << S3 << endl;
        }
        return S1;
    }
};