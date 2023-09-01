/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    set<int> st;
    void dfs(TreeNode* root) {
        if (!root) return ;
        dfs(root -> left);
        st.insert(root -> val);
        dfs(root -> right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        return st.size() > 1 ? *next(st.begin()) : -1;
    }
};