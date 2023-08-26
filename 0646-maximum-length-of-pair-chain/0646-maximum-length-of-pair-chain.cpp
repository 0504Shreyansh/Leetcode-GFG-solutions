class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Approach 1 --> DP + Binary Search
        // Approach 2 --> Greedy (sort for ends)
        vector<vector<int>> P(pairs);
        sort(begin(P), end(P), [&](auto &a, auto &b) {
            return (a[1] == b[1]) ? a[0] < b[0] : a[1] < b[1];
        });
        int ans = 1;
        int end = P[0][1];
        int n = P.size();
        for (int i = 1; i < n; i++) {
            if (end < P[i][0]) {
                end = P[i][1];
                ans++;
            }
        }
        return ans;
    }
};