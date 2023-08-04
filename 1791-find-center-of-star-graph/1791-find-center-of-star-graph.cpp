class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> A;
        for (int i = 0; i < min(3, (int)edges.size()); i++) {
            A[edges[i][0]]++, A[edges[i][1]]++;
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