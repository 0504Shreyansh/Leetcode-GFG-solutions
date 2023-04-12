class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        for (int i = 0; i < path.size(); i++) {
            // Ignore the first '/'
            if (path[i] == '/')
                continue;
            
            // Find out the folder name
            string temp;
            while (i < path.size() && path[i] != '/') {
                temp += path[i++];
            }
            
            // Stay in the current folder
            if (temp == ".") {
                continue;
            // Delete the folder
            } else if (temp == "..") {
                if (!st.empty())
                    st.pop();
            }
            // Stay up with the folder
            else {
                st.push(temp);
            }
        }

        string res;
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        return (res.size() == 0) ? "/" : res;
    }
};