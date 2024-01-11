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
    void dfs(TreeNode* root, int &ans, int mini, int maxi) {
        if (!root) return ;
        dfs(root->left, ans, min(root->val, mini), max(root->val, maxi));
        dfs(root->right, ans, min(root->val, mini), max(root->val, maxi));
        ans = max({ans, root->val - mini, maxi - root -> val});
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, root->val, root->val);
        return ans;
    }
};