class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto x : s) {
            if(x=='*') {
                st.pop();
            } else {
                st.push(x);
            }
        }
        string ans;
        while(st.size()) {
            ans += st.top();
            st.pop();
        }    
        reverse(begin(ans),end(ans));
        return ans;
    }
};