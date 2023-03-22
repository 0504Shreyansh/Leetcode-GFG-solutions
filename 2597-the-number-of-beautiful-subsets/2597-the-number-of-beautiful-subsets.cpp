class Solution {
public:
    bool check(vector<int>& v, int val, int k) {
        for(auto x : v) 
            if(abs(x-val)==k)
                return false;
        return true;
    }
    int solve(int i, int n, vector<int> &v, vector<int>& nums, int k) {
        if(i<0) {
            return (v.size()==0) ? 0 : 1;
        }
        
        int take = 0;
        int notTake = solve(i-1, n, v, nums, k);
        if(check(v, nums[i], k)) {
            v.push_back(nums[i]);
            take = solve(i-1, n, v, nums, k);
            v.pop_back();
        }
        return take + notTake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> v;
        return solve(n-1, n, v, nums, k);
        
    }
};