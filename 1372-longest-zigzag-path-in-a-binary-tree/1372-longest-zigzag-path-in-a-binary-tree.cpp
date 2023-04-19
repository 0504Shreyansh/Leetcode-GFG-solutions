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
    int traverse(TreeNode* root, bool dir) {
        if(!root) 
            return -1;
        // Alternating direction
        return (dir) ? 1+traverse(root->left, !dir) : 1+traverse(root->right, !dir);
    }
    int height(TreeNode* root) {
        return (root==NULL) ? 0 : (1+max(height(root->left), height(root->right)));
    }
    int longestZigZag(TreeNode* root) {
        
        int res = 0;
        int h = height(root);
        queue<TreeNode*> Q({root});
        int level = 0;
        while (Q.size()) {
            int size = Q.size();
            while (size--) {
                TreeNode* node = Q.front();
                Q.pop();
                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
                // Check for longest zig-zag path
                if (res > h) break;
                res = max({res, traverse(node, 0), traverse(node, 1)});
            }
            h--;
        }
        
        return res;
    }
};