class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int res = 0;
        sort(begin(nums),end(nums));
        for (int n : nums)
            if (n > nums[res])
                res++;
        return res;
    }
};