class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp = {nums[0]};
        for (auto &num : nums) {
            int idx = lower_bound(begin(temp), end(temp), num) - begin(temp);
            if (idx >= temp.size()) {
                temp.push_back(num);      
            } else {
                temp[idx] = num;
            }
        }
        return (int)temp.size();
    }
};