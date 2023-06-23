class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto &it : asteroids) {
            if(it > 0 || st.empty()) {
                st.push(it);
            } else {
                if(st.top() < 0) {
                    st.push(it);
                } else if(st.top() > abs(it)) {
                    continue;
                } else if(st.top() == abs(it)) {
                    st.pop();
                } else {
                    bool f = 0;
                    while(st.size() && st.top() > 0 && st.top() <= abs(it)) {
                        if(st.top() == abs(it)) {
                            st.pop(); f = 1;
                            break;
                        } st.pop();
                    }
                    if(st.size() && st.top() >= abs(it)) continue;
                    if(!f) st.push(it);
                }
            }
        }
        vector<int> res(st.size());
        while(st.size()) {
            res[st.size() - 1] = st.top();
            st.pop();
        }
        return res;
    }
};