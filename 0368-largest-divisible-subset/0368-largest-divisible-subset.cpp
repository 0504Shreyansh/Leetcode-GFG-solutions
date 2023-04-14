class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> trace(n, 1);
        int ind = -1, maxi = -1;
        for(int i = 0; i < n; i++) {
            trace[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]) {
                    dp[i] = 1 + dp[j];
                    trace[i] = j;
                }
            }
            if(maxi < dp[i]) {
                maxi = dp[i];
                ind = i;
            }
        }

        vector<int> ans = {nums[ind]};
        while(trace[ind] != ind) {
            ans.push_back(nums[trace[ind]]);
            ind = trace[ind];
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};