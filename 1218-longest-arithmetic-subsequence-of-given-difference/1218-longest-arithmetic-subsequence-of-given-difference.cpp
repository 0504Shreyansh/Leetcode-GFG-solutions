class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> dp;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1 + dp[arr[i] - difference];
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};