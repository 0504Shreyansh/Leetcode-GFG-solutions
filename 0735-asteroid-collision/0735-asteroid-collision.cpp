class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto &it : asteroids) {
            if (st.empty() || it > 0) {
                st.push(it);
            } else if (st.top() < 0 && it < 0) {
                st.push(it);
            } else {
                while (st.size() && st.top() > 0 && it < 0 && st.top() < abs(it)) {
                    st.pop();
                }
                if (st.empty()) {
                    st.push(it);
                } else if (st.top() < 0) {
                    st.push(it);
                } else if (st.top() == abs(it) && it < 0) {
                    st.pop();
                }
            }
        }   
        vector<int> res;
        while (st.size()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};