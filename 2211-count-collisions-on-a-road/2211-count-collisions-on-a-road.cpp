class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int ans = 0;
        for (auto &it : directions) {
            if (it == 'L') {
                if (st.empty()) {
                    st.push(it);
                } else if (st.top() == 'S') {
                    ans++;  // remove (S + L)'s collisions
                } else if (st.top() == 'L') {
                    st.push(it);
                } else {   // (R + L) --> S
                    ans += 2; 
                    st.pop();  // further (R + S)'s collisions
                    while (st.size() && st.top() == 'R') {
                        ans++;
                        st.pop();
                    }
                    st.push('S');
                }
            } else if (it == 'R') { // no collisions at the moment
                st.push(it);
            } else {  // remove (R + S)'s collisions
                while (st.size() && st.top() == 'R') {
                    ans++;
                    st.pop();
                }
                st.push(it);
            }
        }
        return ans;
    }
};