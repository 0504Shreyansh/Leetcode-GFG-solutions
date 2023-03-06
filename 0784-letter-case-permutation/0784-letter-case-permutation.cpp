class Solution {
public:
    vector<string> perms;
    void solve(int i, string s) {
        if(i==s.size()) 
            perms.push_back(s);
        else {
            if(s[i]>=65 && s[i]<=92) {
                s[i] += 32;
                solve(i+1, s);
                s[i] -= 32;
                solve(i+1, s);
            } 
            else if(s[i]>=97 && s[i]<=122) {
                s[i] -= 32;
                solve(i+1, s);
                s[i] += 32;
                solve(i+1, s);
            }
            else {
                solve(i+1, s);
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(0, s);
        return perms;
    }
};