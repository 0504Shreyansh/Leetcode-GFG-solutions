class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return (*prev(prev(end(nums))) - 1) * (*prev(end(nums)) - 1);
    }
};