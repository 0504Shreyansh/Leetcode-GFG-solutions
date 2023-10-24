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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q({root});
        while (q.size()) {
            int size = q.size(), curr = INT_MIN;
            while (size--) {
                TreeNode* C = q.front();
                q.pop();
                curr = max(curr, C -> val);
                if (C -> left) q.push(C -> left);
                if (C -> right) q.push(C -> right);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};