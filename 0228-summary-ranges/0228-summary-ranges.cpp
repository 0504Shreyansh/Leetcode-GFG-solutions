class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int prev = 0, curr = 0;
        int n = nums.size();
        while(curr < n) {
            int first = prev;
            curr++;
            while(curr < n && nums[prev] + 1 == nums[curr]) {
                prev = curr;
                curr++;
            }
            string summary;
            summary = (first != prev) ?  to_string(nums[first]) + "->" + to_string(nums[prev])
                     : to_string(nums[first]);
            ans.push_back(summary);
            first = prev;
            prev++;
        }
        return ans;
    }
};