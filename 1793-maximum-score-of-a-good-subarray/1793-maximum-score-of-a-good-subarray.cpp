class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k], minNum = nums[k];
        int i = k, j = k, n = nums.size();
        while (i >= 0 || j < n) {
            while (i >= 0 && nums[i] >= minNum) i--;
            while (j < n && nums[j] >= minNum) j++;
            ans = max(ans, minNum * (j - i - 1));
            minNum = max((i >= 0) ? nums[i] : -1, (j < n) ? nums[j] : -1);
        }
        return ans;
    }
};