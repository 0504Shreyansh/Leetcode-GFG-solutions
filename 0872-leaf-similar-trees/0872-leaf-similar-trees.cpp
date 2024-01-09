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
    void dfs(TreeNode* root, vector<int>& leafs) {
        if (!root) return ;
        dfs(root->left, leafs);
        if (!root->left && !root->right) leafs.push_back(root->val);
        dfs(root->right, leafs);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1, leafs2;
        dfs(root1, leafs1);
        dfs(root2, leafs2);
        return (leafs1 == leafs2);
    }
};