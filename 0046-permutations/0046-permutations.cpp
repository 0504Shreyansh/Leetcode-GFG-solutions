class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<vector<int>> res = {nums};
        while (next_permutation(begin(nums),end(nums))) {
            res.push_back(nums);
        }
        return res;
    }
};