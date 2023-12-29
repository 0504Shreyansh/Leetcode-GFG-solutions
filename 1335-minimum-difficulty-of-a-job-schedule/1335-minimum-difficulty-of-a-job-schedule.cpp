class Solution {
private:
    int f(int i, int N, int d, vector<int>& jobs, vector<vector<int>>& dp) {
        if (i == N) return (d == 0) ? 0 : 1e6; 
        int& ans = dp[i][d], maxi = 0;
        if (ans != -1) return ans;
        ans = 1e6;
        for (int j = i; j < N; j++) {
            maxi = max(maxi, jobs[j]);
            ans = min(ans, maxi + min(d > 0 ? f(j + 1, N, d - 1, jobs, dp) : 1000000, f(j + 1, N, d, jobs, dp)));
        }
        return ans;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int N = jobDifficulty.size();
        vector<vector<int>> dp(N + 1, vector<int> (d + 1, -1));
        int ans = f(0, N, d, jobDifficulty, dp);
        return (ans > 1e5 + 1 ? -1 : ans);
    }
};