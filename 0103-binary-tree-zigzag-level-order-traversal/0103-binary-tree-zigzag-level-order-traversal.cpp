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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        bool R = 0;
        queue<TreeNode*> q({root});
        while (q.size()) {
            int size = q.size();
            vector<int> temp;
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if (cur -> left) q.push(cur -> left);
                if (cur -> right) q.push(cur -> right);
            }
            if (R) reverse(begin(temp), end(temp));
            R = !R;
            res.push_back(temp);
        }
        return res;
    }
};