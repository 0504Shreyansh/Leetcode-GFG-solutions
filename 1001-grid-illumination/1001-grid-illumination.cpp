class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        unordered_map<int,int> plusD;
        unordered_map<int,int> negD;
        map<pair<int,int>,int> lamp;
        
        for(auto &it : lamps) {
            if(lamp[{it[0], it[1]}]) continue;
            row[it[0]]++;
            col[it[1]]++;
            plusD[it[0] + it[1]]++;
            negD[it[1] - it[0]]++;
            lamp[{it[0], it[1]}]++;
        }
        
        vector<int> ans;
        for(auto &q : queries) {
            int r = q[0], c = q[1];
            if(row[r] || col[c] || plusD[c + r] || negD[c - r]) {
                ans.push_back(1);
            }
            else {
                ans.push_back(0);
            }
            
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    int R = r + i;
                    int C = c + j;
                    if(lamp[{R, C}]) {
                        if(--lamp[{R, C}] == 0) lamp.erase({R, C});
                        if(--row[R] == 0) row.erase(R);
                        if(--col[C] == 0) col.erase(C);
                        if(--plusD[R+C] == 0) plusD.erase(R+C);
                        if(--negD[C-R] == 0) negD.erase(C-R);
                    }
                }
            }
        }
        
        return ans;
    }
};