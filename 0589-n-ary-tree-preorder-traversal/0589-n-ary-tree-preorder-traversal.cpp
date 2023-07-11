/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root == nullptr) return {}; 
        vector<int> res;
        stack<Node*> st;
        st.push(root);
        while(st.size()) {
            Node *cur = st.top();
            st.pop();
            res.push_back(cur->val);
            int size = cur->children.size();
            for(int i = size - 1; i >= 0; i--) {
                st.push(cur->children[i]);
            }
        }
        return res;
    }
};