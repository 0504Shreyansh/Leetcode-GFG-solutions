class Solution {
private:
    vector<int> findLastIndex(vector<string>& garbage, int n) {
        vector<int> lastIdx(4, -1);
        for (int i = 0; i < n; ++i) {
            lastIdx[3] += (int)garbage[i].size();
            for (auto &it : garbage[i]) {
                if (it == 'M') {
                    lastIdx[0] = i;
                } else if (it == 'P') {
                    lastIdx[1] = i;
                } else {
                    lastIdx[2] = i;
                }
            }
        }
        return lastIdx;
    }
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> lastIdx = findLastIndex(garbage, n);
        int res = 1 + lastIdx[3];
        for (int i = 0; i < 3; i++) {
            if (lastIdx[i] != -1) {
                res += accumulate(begin(travel), begin(travel) + lastIdx[i], 0);
            }
        }
        return res;
    }
};