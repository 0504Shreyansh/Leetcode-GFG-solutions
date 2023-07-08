class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // store the maximum freq of any char in any of the strings of words2
        // ultimately we need to make sure that all strings chars are present
        // better choice is to check the maximum occ. of any char
        vector<int> maxOcc(26);
        for(auto &it : words2) {
            vector<int> curr(26);
            for(auto &jt : it) {
                int index = jt - 'a';
                curr[index]++;
                maxOcc[index] = max(maxOcc[index], curr[index]);  
            }
        }
        
        vector<string> res;
        for(auto &it : words1) {
            // store count of the current word
            vector<int> curr(26);
            for(auto &jt : it) {
                int index = jt - 'a';
                curr[index]++;
            }
            // check if any char occs doesn't satisfy max occ condtions
            bool canTake = true;
            for(int j = 0; j < 26; j++) {
                if(curr[j] < maxOcc[j]) {
                    canTake = false;
                    break;
                }
            }
            if(canTake) res.push_back(it);
        }
        return res;
    }
};