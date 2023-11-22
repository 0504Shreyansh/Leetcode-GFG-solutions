class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int, stack<int>> mp;
        for (int i = 0; i < n; i++) {
            int m = nums[i].size();
            for (int j = 0; j < m; j++) {
                mp[i + j].push(nums[i][j]);
            }
        }
        vector<int> res;
        for (auto &x : mp) {
            stack<int> temp = x.second;
            while (temp.size()) {
                res.push_back(temp.top());
                temp.pop();
            }
        }
        return res;
    }
};