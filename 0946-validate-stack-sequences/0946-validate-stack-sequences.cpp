class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0, n = pushed.size();

        while(j < n) {

            // Just push the value if the stack is empty
            if(i < n && st.empty()) {
                st.push(pushed[i]);
                i++;
            }

            // Check for popping condition
            else if(!st.empty() && st.top()==popped[j]) {
                st.pop();
                j++;
            }

            // Check if u still have something to push
            else if(i < n) {
                st.push(pushed[i]);
                i++;
            }

            // If u can neither push or pop -> it is not a valid stack sequence
            else {
                return false;
            }
        }

        return st.empty();
    }
};