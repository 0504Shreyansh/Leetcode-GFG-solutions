class Solution {
public:
    int solve(vector<int> &v, int n) {
        vector<int> dp(n, 0);
        dp[0] = v[0];
        dp[1] = max(v[1], v[0]);
        
        for(int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+v[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[1], nums[0]);
        
        vector<int> p,q;
        for (int i = 0; i < n; i++) 
        {
            if (i != 0)
                p.push_back(nums[i]);
            if (i != n-1)
                q.push_back(nums[i]);
        }
        
        int max1 = solve(p, n-1);
        int max2 = solve(q, n-1);
        
        int res = max(max1, max2);
        return res;
        
    }
};