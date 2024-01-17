class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2000), ff(2000);
        for (auto &it : arr) {
            freq[it + 1000]++;
        }
        for (auto &it : freq) {
            if (it != 0) {
                ff[it]++;
            }
        }
        return (count(begin(freq), end(freq), 0) == count(begin(ff), end(ff), 0));        
    }
};