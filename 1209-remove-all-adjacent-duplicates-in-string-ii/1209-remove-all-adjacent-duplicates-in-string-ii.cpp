class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (st.size() && st.top().first==s[i]) {
                int cnt = st.top().second;
                st.pop();
                st.push({s[i], cnt+1});
            } else {
                st.push({s[i], 1});
            }
            // Remove if k letters are accumulated
            if(st.top().second == k) {
                st.pop();
            }
        }
        
        string ans;
        while (st.size()) {
            auto cur = st.top();
            st.pop();
            char ch = cur.first;
            int cnt = cur.second;
            string s(cnt, ch);
            ans += s;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};