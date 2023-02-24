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
public:
    vector<int> nodes;
    void dfs(TreeNode* root) {
        if(!root) 
            return ;
        dfs(root->left);
        nodes.push_back(root->val);
        dfs(root->right);
    }
    void solve(TreeNode* root) {
        if(!root) 
            return ;
        solve(root->right);
        root->val = nodes.back();
        nodes.pop_back();
        solve(root->left);
    } 
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        int n = nodes.size();
        for(int i = n-2; i >= 0; i--) 
            nodes[i] += nodes[i+1];
        solve(root);
        return root;
    }
};