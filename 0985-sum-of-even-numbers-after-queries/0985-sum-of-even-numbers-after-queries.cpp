class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto &it : nums) {
            if(it % 2 == 0) {
                sum += it;
            }
        }
        vector<int> res;
        for(auto &q : queries) {
            int val = q[0];
            int index = q[1];
            if(nums[index] % 2 == 0) {
                if(val % 2 == 0) {
                    sum += val;
                    nums[index] += val;
                } else {
                    sum -= nums[index];
                    nums[index] += val;
                }
            } else {
                if(val % 2 == 0) {
                    nums[index] += val;
                } else {
                    nums[index] += val;
                    sum += nums[index];
                }
            }
            res.push_back(sum);
        }
        return res;
    }
};