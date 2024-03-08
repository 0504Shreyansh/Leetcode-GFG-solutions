class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int f = 0, maxF = 0;
        vector<int> mp(101);
        for (auto &it : nums) {
            ++mp[it];
            if (mp[it] > maxF) {
                f = mp[it];
                maxF = mp[it];
            } else if (mp[it] == maxF) {
                f += mp[it];
            }
        }
        return f;
    }
};