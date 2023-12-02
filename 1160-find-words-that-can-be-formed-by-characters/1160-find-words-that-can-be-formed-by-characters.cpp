class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        vector<int> freq(26);
        for (auto &c : chars) 
            freq[c - 'a']++;
        for (auto &it : words) {
            vector<int> temp(26);
            bool ok = 1;
            for (auto &c : it) {
                if (++temp[c - 'a'] > freq[c - 'a']) {
                    ok = false;
                    break;
                }
            }
            if (ok) 
                res += (int)it.size();
        }
        return res;
    }
};