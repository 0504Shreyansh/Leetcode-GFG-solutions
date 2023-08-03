class Solution {
private:
    vector<string> res;
    void solve(string& cur, int i, string& digits, unordered_map<char, string>& map) {
        if (i >= digits.size()) {
            res.push_back(cur);
            return ;
        }
        for (auto &it : map[digits[i]]) {
            cur.push_back(it);
            solve(cur, i + 1, digits, map);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map = {{'2', "abc"}, {'3', "def"}, 
                                           {'4', "ghi"}, {'5', "jkl"}, 
                                           {'6', "mno"}, {'7', "pqrs"}, 
                                           {'8', "tuv"}, {'9', "wxyz"}};
        string cur = "";
        solve(cur, 0, digits, map);
        if (res.back() == "") res.pop_back();
        return res;
    }
};