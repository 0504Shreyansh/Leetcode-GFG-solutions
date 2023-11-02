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
    int res;
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) return {0, 0};
        pair<int, int> L = dfs(root->left);
        pair<int, int> R = dfs(root->right);
        pair<int, int> ans;
        ans.second = 1 + L.second + R.second;
        if ((root->val + L.first + R.first) / ans.second == root->val) {
            res++;
        }
        ans.first = L.first + R.first + root->val;
        return ans;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};