class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N, 0);
        res[0] = accumulate(begin(nums), end(nums), 0) - (N * nums[0]);
        for (int i = 1; i < N; i++) {
            res[i] = res[i - 1] + (2 * i - N) * (nums[i] - nums[i - 1]);
        } 
        return res;
    }
};