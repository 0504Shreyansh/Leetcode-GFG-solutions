class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> bits(32);
        for(int i = 0; i < n; i++) {
            bitset<32> curr_bits(nums[i]);
            for(int i = 0; i < 32; i++) {
                // numbers occ. 3 times will make bits[i] will become 0
                bits[i] = (bits[i] + curr_bits[i]) % 3;
            }
        }
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            if(bits[i] != 0) {  // number occ. only once
                res |= (1 << i);
            }
        }
        return res;
    }
};