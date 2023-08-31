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
    int maxLevelSum(TreeNode* root) {
        int res = -1e9;
        int level = 1;
        int ans = 1;
        queue<TreeNode*> q({root});
        while (q.size()) {
            int size = q.size();
            int sum = 0;
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur -> left) q.push(cur -> left);
                if (cur -> right) q.push(cur -> right);
            }
            if (res < sum) {
                res = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};