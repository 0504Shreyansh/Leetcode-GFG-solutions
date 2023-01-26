class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        
        int prev = INT_MIN, longest = 1, cnt = 1;
        for(auto i:mp) {
            if(i.first==prev+1) 
                cnt++;
            else 
                cnt=1;
            prev = i.first;
            longest = max(longest,cnt);
        }
        
        return nums.size() ? longest : 0;
    }
};