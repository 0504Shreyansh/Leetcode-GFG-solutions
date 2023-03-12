class Solution {
public:
    vector<string> ans;
    void solve(vector<string> &t, int i, string cur) {
        if(cur.size()==t.size())
            ans.push_back(cur);
        else 
            for(int k = 0; k < t[i].size(); k++) 
                solve(t, i+1, cur+t[i][k]);
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, 
        {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
        vector<string> t;
        for(auto i : digits)
            t.push_back(mp[i]);
        solve(t, 0, "");
        if(ans.back()=="")
            ans.clear();
        return ans;
    }
};