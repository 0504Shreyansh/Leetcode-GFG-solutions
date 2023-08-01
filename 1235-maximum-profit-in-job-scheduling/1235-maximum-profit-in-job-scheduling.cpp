class Solution {
private:
    int findNextIndex(int i, vector<vector<int>>& jobs) {
        int low = i + 1;
        int high = jobs.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[i][1] <= jobs[mid][0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int solve(int i, vector<vector<int>>& jobs, vector<int>& dp) {
        if (i >= jobs.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int notPick = solve(i + 1, jobs, dp);
        int j = findNextIndex(i, jobs);
        int pick = jobs[i][2] + solve(j, jobs, dp);
        return dp[i] = max(pick, notPick);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(begin(jobs),end(jobs));
        vector<int> dp(startTime.size(), -1);
        int ans = solve(0, jobs, dp);
        return ans;
    }
};