class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        int prev = INT_MIN, longest = 1, cnt = 1;
        for(auto i:mp) {
            if(prev==INT_MIN) {
                prev = i.first;
            }
            else if(i.first==prev+1) {
                prev = i.first;
                cnt++;
            }
            else {
                cnt=1;
                prev = i.first;
            }
            longest = max(longest,cnt);
        }
        
        return longest;
    }
};