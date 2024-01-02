class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int size = 0, n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && nums[i] == nums[j]) {
                if (size <= j - i) {
                    ans.push_back({nums[j]});
                    size++;
                } else {
                    ans[j - i].push_back(nums[j]);
                }
                ++j;
            }
            i = j - 1;
        }
        return ans;
    }
};