/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> temp;
    vector<TreeNode*> path1, path2;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return ;
        temp.push_back(root);
        if (root == p) path1 = temp;
        if (root == q) path2 = temp;
        dfs(root->left, p, q);
        dfs(root->right, p, q);
        temp.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        TreeNode* lca = root;
        for (int i = 0; i < min(path1.size(), path2.size()); ++i) {
            if (path1[i] != path2[i]) break;
            lca = path1[i];
        }
        return lca;
    }
};