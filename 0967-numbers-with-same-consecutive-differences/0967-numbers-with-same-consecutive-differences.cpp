class Solution {
public:
    vector<int> res;
    void solve(int n, int k, string s)
    {
        if (s.size()==n)
        {
            res.push_back(stoi(s));
            return ;
        }

        // Do not take the first character to be zero
        if (s.size()==0) 
        {
            for(int i = 1; i < 10; i++)
            {
                solve(n, k, s+char(i+'0'));
            }
        }
        else 
        {
            if(int(s.back()-'0' - k) >= 0)
            {
                solve(n, k, s+to_string(int(s.back()-'0' - k)));
            }
            if(int(s.back()-'0' + k) < 10)
            {
                solve(n, k, s+to_string(int(s.back()-'0' + k)));
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {

        solve(n, k, "");
        
        if(k==0)
        {
            set<int> st;
            for(auto x : res)
                st.insert(x);
            res.clear();
            for(auto x : st)
                res.push_back(x);
        }
        
        return res;
        
    }
};