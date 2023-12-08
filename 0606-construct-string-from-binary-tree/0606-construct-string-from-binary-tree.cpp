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
    string dfs(TreeNode* root, bool left) {
        if (root && !root->left && !root->right) return "(" + to_string(root->val) + ")";
        if (!root) return (left == true) ? "()" : "";
        return "(" + to_string(root->val) + dfs(root->left, 1) + dfs(root->right, 0) + ")";
    }
public:
    string tree2str(TreeNode* root) {
        string ans = dfs(root, 1);
        ans.pop_back();
        ans.erase(ans.begin());
        return ans;
    }
};