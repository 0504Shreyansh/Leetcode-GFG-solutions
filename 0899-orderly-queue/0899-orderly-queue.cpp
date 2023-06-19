class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {  
            // we can always sort as we have atleast 2 pos to swap with 
            sort(begin(s),end(s));
            return s;
        }
        int n = s.size();
        char mini = 'z';
        string res(s);
        for(int i = 0; i < n; i++) {
            if(s[i] <= mini) {
                mini = s[i];
                res = min(res, s.substr(i, n - i) + s.substr(0, i));
            }
        }
        return res;
    }
};