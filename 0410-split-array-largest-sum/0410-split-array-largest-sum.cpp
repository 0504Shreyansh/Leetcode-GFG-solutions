class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int k) {
        int cnt = 1;
        int amount = 0;
        for(auto &it : nums) {
            if(amount + it <= mid) {
                amount += it;
            } else {
                cnt++;
                if(cnt > k) return false;
                if(it > mid) return false;
                amount = it;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for(auto &it : nums)
            sum += it;
        int low = 0;
        int high = sum;
        int res = sum;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(isPossible(mid, nums, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};