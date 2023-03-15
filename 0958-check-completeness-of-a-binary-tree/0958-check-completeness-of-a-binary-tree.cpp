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
    int height(TreeNode* root) {
        return (root) ? 1 + height(root->left) + height(root->right) : 0; 
    }
    bool check(TreeNode* root, int i, int n) {
        if (!root) 
            return true;
        if (i>=n) 
            return false;
        
        return check(root->left,2*i+1,n) && check(root->right,2*i+2,n);
    }
    bool isCompleteTree(TreeNode* root) {
        int n = height(root);
        return check(root,0,n);
    }
};