class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int ans = 0;
        int flips = 0;
        for (int j = 0; j < n; j++) {
            if(nums[j] == 0) flips++;
            while(flips > k) {
                if(nums[i] == 0) flips--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};