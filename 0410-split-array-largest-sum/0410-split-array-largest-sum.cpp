class Solution {
private:
    bool isPossible(int mid, int k, vector<int>& nums) {
        int cnt = 1;
        int sum = 0;
        for (auto &it : nums) {
            if (sum + it <= mid) {
                sum += it;
            } else {
                cnt++;
                sum = it;
                if (it > mid || cnt > k) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = nums[0];  
        int high = 0;
        for (auto &it : nums) {
            high += it;
        }
        int res = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid, k, nums)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};