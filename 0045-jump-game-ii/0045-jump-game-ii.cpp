class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size(), start = 0, end = 0;
        int jumps = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            int curr = i + nums[i];
            start = max(start, curr);
            if(i==end && i!=n-1) {
                end = start;
                jumps++;
            }
        }
        return jumps;
    }
};