class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26);
        for (auto &it : s) 
            freq[it - 'a']++;
        for (auto &it : t) {
            if (--freq[it - 'a'] < 0)
                return it;
        }
        return '#';
    }
};