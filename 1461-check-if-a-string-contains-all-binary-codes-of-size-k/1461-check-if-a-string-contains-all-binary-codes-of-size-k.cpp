class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> binarys;
        string tmp;
        for(int i = 0; i < s.size(); i++) {
            tmp += s[i];
            // Maintain k sized window for all the binarys
            if(tmp.size()==k) {
                binarys.insert(tmp);
                tmp.erase(tmp.begin());
            }
        }
        // Check if the set contains 2^k unique strings of k size
        return (binarys.size()==pow(2, k));
    }
};