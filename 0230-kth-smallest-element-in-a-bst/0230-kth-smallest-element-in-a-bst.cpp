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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        while (root) {
            if (root -> left == NULL) {
                 if (--k == 0) ans = root->val;
                root = root -> right;
            } else {
                TreeNode* curr = root -> left;
                while (curr->right != NULL && curr->right != root)
                    curr = curr -> right;
                if (curr -> right == NULL) {
                    curr -> right = root;
                    root = root -> left;
                } else {
                    if (--k == 0) ans = root->val;
                    root = root -> right;
                    curr -> right = NULL;
                }
            }
        }
        return ans;
    }
};