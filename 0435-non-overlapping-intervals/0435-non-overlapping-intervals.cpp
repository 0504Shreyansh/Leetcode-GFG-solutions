class Solution {
private:
    int nextIndex(int i, vector<vector<int>>& intervals) {
        int low = i + 1, high = intervals.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (intervals[i][1] <= intervals[mid][0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    int f(int i, vector<vector<int>>& intervals, vector<int>& dp) {
        if(i >= intervals.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int notPick = f(i + 1, intervals, dp), pick = 0;
        int j =  nextIndex(i, intervals);
        pick = 1 + f(j, intervals, dp);
        return dp[i] = max(notPick, pick);
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals),end(intervals));
        vector<int> dp(n + 1, -1);
        return n - f(0, intervals, dp);
    }
};