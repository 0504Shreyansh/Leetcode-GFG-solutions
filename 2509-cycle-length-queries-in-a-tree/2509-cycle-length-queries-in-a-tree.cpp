class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto &q : queries) {
            int a = q[0], b = q[1];
            map<int, int> m;
            while (a) {m[a]++, a /= 2;}
            while (b) {m[b]++, b /= 2;}
            int node = 1;
            for (auto &it : m) {
                if (it.second > 1) {
                    node = it.first;
                }
            }
            int sa = 0, sb = 0;
            while (q[0] > node) q[0] /= 2, sa++;
            while (q[1] > node) q[1] /= 2, sb++;
            ans.push_back(1 + sa + sb);
        }
        return ans;
    }
};