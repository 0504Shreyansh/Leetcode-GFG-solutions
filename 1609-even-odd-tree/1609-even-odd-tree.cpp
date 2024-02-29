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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q({root});
        while (q.size()) {
            int size = q.size(), prev;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (i > 0) {
                    if (level % 2 == 0 && prev >= cur -> val) return false;
                    if (level % 2 == 1 && prev <= cur -> val) return false;
                }
                if (level % 2 == cur -> val % 2) return false; 
                prev = cur->val;
                if (cur -> left) q.push(cur -> left);
                if (cur -> right) q.push(cur -> right);
            }
            level++;
        }
        return true;
    }
};