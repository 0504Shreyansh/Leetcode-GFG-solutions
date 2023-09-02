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
    int dfs(TreeNode* root, int dir) {
        if (!root) return -1;
        return (dir == 0) ? 1 + dfs(root -> left, 1) : 1 + dfs(root -> right, 0);
    }
    int height(TreeNode* root) {
        return (!root) ? 0 : 1 + max(height(root->left), height(root->right));
    }
public:
    int longestZigZag(TreeNode* root) {
        int H = height(root);
        queue<TreeNode*> q({root});
        int ans = 0;
        int level = 1;
        while (q.size()) {
            int size = q.size();
            while (size--) {
                TreeNode *cur = q.front();
                q.pop();
                if (ans < H - level) {
                    ans = max({ans, dfs(cur, 0), dfs(cur, 1)});
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            level++;
        }
        return ans;
    }
};