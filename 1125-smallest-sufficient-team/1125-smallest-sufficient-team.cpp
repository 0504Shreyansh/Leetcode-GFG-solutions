class Solution {
public:
    void solve(int i, int mask, vector<string>& req_skills, vector<vector<string>>& people, vector<int>& temp, vector<int>& ans, vector<int>& masks) {
        if(i >= req_skills.size()) {
            if(mask == (1 << req_skills.size()) - 1) {
                if(temp.size() < ans.size()) {
                    ans = temp;
                }
            }
            return ;
        }

        
        if(mask & (1 << i)) {  // leave
            solve(i + 1, mask, req_skills, people, temp, ans, masks);
        } else {   // look fo rbetter oppurtunities
            for(int j = 0; j < people.size(); ++j) {
                if(masks[j] & (1 << i)) {
                    temp.push_back(j);
                    solve(i + 1, mask | masks[j], req_skills, people, temp, ans, masks);
                    temp.pop_back();
                }
            }
        }
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string, int> mp;
        for(int i = 0; i < req_skills.size(); ++i) {
            mp[req_skills[i]] = i;
        }


        vector<int> masks;
        for(auto &it : people) {
            int curr = 0;
            for(auto &j : it) {
                curr |= (1 << mp[j]);
            }
            masks.push_back(curr);
        }
        
        vector<int> temp;
        vector<int> ans(20, -1);
        solve(0, 0, req_skills, people, temp, ans, masks);
        
        return ans;
    }
};