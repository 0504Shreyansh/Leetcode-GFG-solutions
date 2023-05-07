class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int N = size(obstacles);
        vector<int> tmpLIS;
        vector<int> ans(N);
        for (int i = 0; i < N; i++) {
            auto it = upper_bound(begin(tmpLIS),end(tmpLIS),obstacles[i]) - begin(tmpLIS);
            if (it >= tmpLIS.size()) {
                tmpLIS.push_back(obstacles[i]);
            }
            else {
                tmpLIS[it] = obstacles[i];
            }
            // (it + 1) -> length of the LIS with obstacles[i] as the last 
            ans[i] = it + 1;
        }
        return ans;
    }
};