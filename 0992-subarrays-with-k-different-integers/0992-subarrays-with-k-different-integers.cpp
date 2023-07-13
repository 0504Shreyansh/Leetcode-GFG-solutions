class Solution {
public:
    int count(vector<int>& nums, int k, int maximum) {
        vector<int> mp(maximum + 1, 0);
        int i = 0;
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(++mp[nums[j]] == 1) {
                cnt++;
            }
            while(cnt > k) {
                if(--mp[nums[i]] == 0) {
                    cnt--;
                }
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int maximum = 0;
        for(auto &it : nums)
            maximum = max(maximum, it);
        return count(nums, k, maximum) - count(nums, k - 1, maximum);
    }
};