class Solution {
private:
    int findNextIndex(int i, vector<vector<int>>& P) {
        int low = i + 1, high = P.size() - 1;
        int idx = high + 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (P[i][1] < P[mid][0]) {
                idx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return idx;
    }
    int solve(int i, vector<vector<int>>& P, vector<int>& dp) {
        if (i >= P.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int nextIdx = findNextIndex(i, P);
        int notPick = solve(i + 1, P, dp);
        int pick = 1 + solve(nextIdx, P, dp);
        return dp[i] = max(pick, notPick);
    }
public:
    int findLongestChain(vector<vector<int>> pairs) {
        vector<vector<int>> P(pairs);
        sort(begin(P), end(P), [&](auto &a, auto &b) {
            return a[0] < b[0];
        });
        vector<int> dp(P.size(), -1);
        return solve(0, P, dp);
    }
};