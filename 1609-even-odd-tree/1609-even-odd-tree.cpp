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
    bool check(int level, int curr, int prev) {
        if (level % 2 == 0) {
            if (curr % 2 == 0 || prev >= curr) {
                return false;
            }
        } else {
            if (curr % 2 == 1 || prev <= curr) {
                return false;
            }
        }
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q({root});
        int level = 0;
        while (!q.empty()) {
            int size = q.size(), prev;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (i > 0 && !check(level, curr->val, prev)) {
                    return false;
                } else if (i == 0 && (curr->val & 1) == (level & 1)) {
                    return false;
                }
                prev = curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            level++;
        }
        return true;
    }
};