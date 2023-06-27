class Solution {
public:
    bool isValid(string &s) {
        if(s.size() > 1 && s[0] == '0') {
            return false;
        }
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }
    void solve(int index, string &s, int segCount, vector<string> &segs, vector<string>& res) {
        
        if(index >= s.size()) {
            if(segCount == 4) {
                res.push_back(segs[0]+'.'+segs[1]+'.'+segs[2]+'.'+segs[3]);
            }
            return ;
        }
        
        string curr;
        for(int j = index; j <= min(index + 2, (int)s.size() - 1); j++) {
            curr += s[j];
            if(isValid(curr)) {
                segs.push_back(curr);                
                solve(j + 1, s, segCount + 1, segs, res);
                segs.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, segs;
        solve(0, s, 0, segs, res);
        return res;
    }
};