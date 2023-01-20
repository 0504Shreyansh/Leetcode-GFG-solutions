class Solution {
public:
    void f(set<vector<int>>&s, vector<int>&v, vector<int> &nums, int i, int n) {
        if(is_sorted(v.begin(),v.end()) && v.size()>1) {
            s.insert(v);
        }
        if(i>=n) 
            return ;
        v.push_back(nums[i]);
        f(s,v,nums,i+1,n);
        v.pop_back();
        f(s,v,nums,i+1,n);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        set<vector<int>> s;
        int i=0, n=nums.size();
        f(s,v,nums,i,n);
        for(auto x:s)
            ans.push_back(x);
        return ans;
    }
};