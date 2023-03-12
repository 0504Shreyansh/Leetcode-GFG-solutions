class Solution {
public:
    vector<string> res;
    bool isValid(string s) {
        int bracs = 0;
        for (auto c : s) {
            if (c=='(') bracs++;
            else bracs--;
            if (bracs < 0) return false;
        }
        return (bracs==0);
    }
    void solve(int ob, int cb, int n, string cur) {
        if (ob==0 && cb==0 && isValid(cur)) {
            res.push_back(cur);
        } else {
            if (ob) 
                solve(ob-1, cb, n, cur+'(');
            if (cb) 
                solve(ob, cb-1, n, cur+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n, n, n, "");
        return res;
    }
};