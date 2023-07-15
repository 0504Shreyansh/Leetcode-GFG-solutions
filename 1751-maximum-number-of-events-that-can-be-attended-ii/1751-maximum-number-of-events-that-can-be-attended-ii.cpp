class Solution {
private:
    int findNextPossibleIndex(int i, vector<vector<int>>& events) {
        int low = i; 
        int high = events.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(events[mid][0] > events[i][1]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int f(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        if(i >= events.size() || k == 0) {
            return 0;
        }
        if(dp[i][k] != -1) {
            return dp[i][k];
        }
        int notPick = f(i + 1, events, k, dp), pick = 0;
        int newIndex = findNextPossibleIndex(i, events);
        pick = events[i][2] + f(newIndex, events, k - 1, dp);
        return dp[i][k] = max(pick, notPick);
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events),end(events));
        vector<vector<int>> dp(events.size(), vector<int> (k + 1, -1));
        return f(0, events, k, dp);
    }
};