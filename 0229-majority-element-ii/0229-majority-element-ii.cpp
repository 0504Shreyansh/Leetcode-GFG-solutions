class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = -2e9, ele2 = -2e9;
        int count1 = 0, count2 = 0;
        for (auto &x : nums) {
            if (x == ele1) count1++;
            else if (x == ele2) count2++;
            else if (count1 == 0) ele1 = x, count1 = 1;
            else if (count2 == 0) ele2 = x, count2 = 1;
            else count1--, count2--;
        }
        vector<int> ans;
        count1 = count2 = 0;
        for (auto &it : nums) {
            if (it == ele1) count1++;
            else if (it == ele2) count2++;
        }
        if (count1 > (int)(nums.size()) / 3) 
            ans.push_back(ele1);
        if (count2 > (int)(nums.size()) / 3) 
            ans.push_back(ele2);
        return ans;
    }
};