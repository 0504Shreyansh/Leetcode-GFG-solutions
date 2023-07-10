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
    void findMinDepth(TreeNode* root, int depth, int &ans) {
        if(root == nullptr) {
            return ;
        }
        if(!root->left && !root->right) {
            ans = min(ans, depth);
            return ;
        }
        findMinDepth(root->left, depth + 1, ans);
        findMinDepth(root->right, depth + 1, ans);
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 1e6;
        findMinDepth(root, 1, ans);
        return ans;
    }
};