class Solution {
private:
    int findNextIndex(int i, vector<vector<int>>& rides) {
        int low = i + 1;
        int high = rides.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (rides[i][1] <= rides[mid][0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    long long solve(int i, vector<vector<int>>& rides, vector<long long>& dp) {
        if (i >= rides.size()) return 0;
        if (dp[i] != -1) return dp[i];
        long long notPick = solve(i + 1, rides, dp);
        int j = findNextIndex(i, rides);
        long long pick = rides[i][1] - rides[i][0] + rides[i][2] + solve(j, rides, dp);
        return dp[i] = max(notPick, pick);    
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(begin(rides),end(rides));
        vector<long long> dp(rides.size(), -1);
        long long ans = solve(0, rides, dp);
        return ans;
    }
};