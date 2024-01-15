class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int, int> lost;
        for (auto &it : matches) {
            if (lost.find(it[0]) == lost.end()) {
                lost[it[0]] = 0;
            }
            lost[it[1]]++;
        }
        for (auto &it : lost) {
            if (it.second == 0) {
                ans[0].push_back(it.first);
            } else if (it.second == 1) {
                ans[1].push_back(it.first);
            }
        }
        return ans;
    }
};