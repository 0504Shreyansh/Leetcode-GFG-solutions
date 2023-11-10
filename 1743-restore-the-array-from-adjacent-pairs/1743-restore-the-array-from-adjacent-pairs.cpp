class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        map<int, vector<int>> mp;
        for (auto &it : adjacentPairs) {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        
        vector<int> res;
        for (auto &it : mp) {
            if (it.second.size() == 1) {
                res.push_back(it.first);
                res.push_back(it.second[0]);
                mp.erase(it.first);
                break;
            } 
        }
                
        int prev = res.back(), prevPrev = res[0];
        while (res.size() != n) {
            vector<int> temp = mp[prev];
            for (int &it : temp) {
                if (it != prevPrev) {
                    res.push_back(it);
                    prevPrev = prev;
                    prev = it;
                    mp.erase(prevPrev);
                    break;
                }
            } 
        }
        return res;
    }
};