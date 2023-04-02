class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort according to the second parameter
        sort(begin(pairs),end(pairs),[&](auto &a, auto &b) {
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int N = pairs.size();
        int ans = 1, end = pairs[0][1];
        for(int i = 1; i < N; i++) {
            if(end < pairs[i][0]) {
                ans++;
                end = pairs[i][1];
            }
        }
        return ans;
    }
};