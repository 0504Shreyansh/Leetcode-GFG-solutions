class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return 1;
        map<int, int> truster, trusted;
        for (auto &it : trust) {
            truster[it[0]]++, trusted[it[1]]++;
        }
        for (auto &it : trusted) {
            if (truster[it.first] == 0 && it.second == n - 1) {
                return it.first;
            }
        }
        return -1;
    }
};