class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int ans = 0;
        for (auto &it : directions) {
            if(it == 'R') {
                st.push(it);
            } else if(it == 'L') {
                if(st.size()) {
                    if(st.top() == 'R') {
                        ans += 2;
                        st.pop();
                        while(st.size() && st.top() == 'R') {
                            ans++;  // ?
                            st.pop();
                        }
                        st.push('S');
                    
                    } else if(st.top() == 'L') {
                        st.push(it);
                    } else {
                        ans++;
                        continue;
                    }
                } else {
                    st.push(it);
                }
            } else {
                while(st.size() && st.top() == 'R') {
                    ans++;
                    st.pop();
                }
                st.push(it);
            }
        }
        return ans;
    }
};