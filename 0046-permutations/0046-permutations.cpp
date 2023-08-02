class Solution {
private:
    void f(int mask, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return ;
        }
        for (int i = 0; i < nums.size(); i++) {
            if ((mask & (1 << i)) == 0) {
                temp.push_back(nums[i]);
                f(mask | (1 << i), nums, temp, res);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        f(0, nums, temp, res);
        return res;
    }
};