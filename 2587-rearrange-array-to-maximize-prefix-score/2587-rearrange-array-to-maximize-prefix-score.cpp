class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<long> temp;
        for(auto x : nums)
            temp.push_back(x);
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        for(int i = 1; i < temp.size(); i++)
            temp[i] += temp[i-1];
        int res = 0;
        for(auto i : temp)
            res += (i>0);
        return res;
    }
};