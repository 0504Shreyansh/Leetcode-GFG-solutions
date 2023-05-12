class Solution {
public:
    // Memoization solution -> gives TLE!
    long long solve(int i, vector<vector<int>>& A, vector<long long>& dp) {
        if(i >= A.size()) {
            return 0;
        }
        if(dp[i] != -1LL) {
            return dp[i];
        }
        long long solveIt = A[i][0] + solve(i + A[i][1] + 1, A, dp);
        long long skip = solve(i + 1, A, dp);
        return max(skip, solveIt);
    }
    long long mostPoints(vector<vector<int>>& A) {
        int N = A.size();
        vector<long long> dp(N + 1, 0);
        // return solve(0, A, dp);
        dp[N - 1] = A[N - 1][0];
        for(int i = N - 2; i >= 0; i--) {
            long long skipIt = dp[i + 1];
            long long solveIt = A[i][0];
            if(i + 1 + A[i][1] <= N) {
                solveIt += dp[i + 1 + A[i][1]];
            }
            dp[i] = max(skipIt, solveIt);
        }
        return dp[0];
    }
};