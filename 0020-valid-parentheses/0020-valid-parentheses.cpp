class Solution {
public:
    bool matches(char c1, char c2) {
        return ((c1==')' && c2=='(') || (c1==']' && c2=='[') || (c1=='}' && c2=='{'));
    }
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(st.size() && matches(c, st.top())) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        return (st.empty());
    }
};