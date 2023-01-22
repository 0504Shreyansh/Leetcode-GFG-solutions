class Solution {
public:
    unordered_map<int,vector<int>> mp;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int n = mp[target].size();
        int ran = mp[target][rand()%n];
        return ran;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */