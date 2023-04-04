class Solution {
public:
    int partitionString(string s) {
        vector<int> freq(26, 0);
        int partitions = 1;
        for(auto ch : s) {
            if(freq[ch-'a']) {
                partitions++;
                freq.clear();
                freq.resize(26);
            }
            freq[ch-'a']++;
        }
        return partitions;
    }
};