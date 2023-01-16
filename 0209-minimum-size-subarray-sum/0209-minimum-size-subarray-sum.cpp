class Solution {
/*1. Almost similar to maximum size subarray of sum k.
  2. Only change is to apply atleast sum k.
  3. Apply variable size sliding window concept.
*/
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0, j = 0, ans = INT_MAX;
        int sum = 0;
        
        while(j<nums.size()) {
            sum += nums[j];
            while(sum>=target) {
                ans = min(ans, j-i+1);
                sum -= nums[i++];
            } 
            j++;
            // cout << i << ' ' << j << ' ' << sum << ' ' << ans << endl;
        }
        
        return (ans==INT_MAX) ? 0 : ans;
    }
};