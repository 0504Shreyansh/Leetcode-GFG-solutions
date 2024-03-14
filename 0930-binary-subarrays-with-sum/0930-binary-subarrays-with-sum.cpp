class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0, sum = 0;
        map<int, int> mp = {{0, 1}};
        for (int &x : nums) {
            sum += x;
            ans += mp[sum - goal];
            ++mp[sum];
        }
        return ans;
    }
};