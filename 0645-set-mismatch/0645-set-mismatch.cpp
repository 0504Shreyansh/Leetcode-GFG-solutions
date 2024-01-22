class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int X = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            X ^= nums[i];
            X ^= (i + 1);
        }
        int diffBit = 0;
        for (int b = 0; b < 20; b++) {
            if (X >> b & 1) {
                diffBit = b;
                break;
            } 
        }
        int x1 = X, x2 = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] >> diffBit & 1) == 0) {
                x1 ^= nums[i];
                x2 ^= nums[i];
            }
            if (((i + 1) >> diffBit & 1) == 0) {
                x1 ^= (i + 1);
                x2 ^= (i + 1);
            }
        }
        int occ = 0;
        vector<int> ans = {x1, x2};
        for (auto &it : nums) occ += (it == x1);
        if (occ == 0) swap(ans[0], ans[1]);
        return ans;
    }
};