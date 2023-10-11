class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> m;
        for (auto &it : flowers) {
            m[it[0]]++, m[it[1] + 1]--;
        }
        vector<vector<int>> P;
        for (auto &it : m) {
            P.push_back({it.first, it.second});
        }
        int n = P.size();
        for (int i = 1; i < n; i++) {
            P[i][1] += P[i - 1][1];
        }
        vector<int> ans;
        for (auto &it : people) {
            int time = it;
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (P[mid][0] <= time) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (high >= 0) ans.push_back(P[high][1]);
            else ans.push_back(0);
        }
        return ans;
    }
};