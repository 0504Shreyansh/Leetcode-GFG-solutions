class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> A;
        for (auto &it : edges) {
            A[it[0]]++, A[it[1]]++;
        }
        int deg = 0, node = -1;
        for (auto &it : A) {
            if (it.second > deg) {
                deg = it.second;
                node = it.first;
            }
        }
        return node;
    }
};