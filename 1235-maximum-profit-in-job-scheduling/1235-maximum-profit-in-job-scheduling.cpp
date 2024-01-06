class Solution {
private:
    int findNextIdx(int i, int N, vector<array<int, 3>>& jobs) {
        int low = i + 1, high = N - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            (jobs[i][1] <= jobs[mid][0]) ? high = mid - 1 : low = mid + 1;
        }
        return low;
    }
    int solve(int i, int N, vector<array<int, 3>>& jobs, vector<int>& dp) {
        if (i == N) return 0;
        int& ans = dp[i];
        if (ans != -1) return ans;
        ans = solve(i + 1, N, jobs, dp);
        int nextIdx = findNextIdx(i, N, jobs);
        ans = max(ans, jobs[i][2] + solve(nextIdx, N, jobs, dp));
        return ans;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = profit.size();
        vector<array<int, 3>> jobs;
        for (int i = 0; i < N; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(begin(jobs), end(jobs));
        vector<int> dp(N, -1);
        return solve(0, N, jobs, dp);
    }
};