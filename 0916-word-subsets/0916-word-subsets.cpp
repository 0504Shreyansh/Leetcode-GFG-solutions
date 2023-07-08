class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        vector<int> pre(26);
        for(int i = 0; i < words2.size(); i++) {
            vector<int> curr(26);
            for(int j = 0; j < words2[i].size(); j++) {
                int index = words2[i][j] - 'a';
                curr[index]++;
                pre[index] = max(pre[index], curr[index]);
            }
        }
        vector<string> res;
        for(int i = 0; i < n; i++) {
            vector<int> curr(26);
            for(int j = 0; j < words1[i].size(); j++) {
                int index = words1[i][j] - 'a';
                curr[index]++;
            }
            bool canTake = true;
            for(int j = 0; j < 26; j++) {
                if(curr[j] < pre[j]) {
                    canTake = false;
                    break;
                }
            }
            if(canTake) res.push_back(words1[i]);
        }
        return res;
    }
};