class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        return ceil(1.0*abs(accumulate(nums.begin(),nums.end(),0LL)-goal)/limit);
    }
};