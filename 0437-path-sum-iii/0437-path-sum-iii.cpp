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
    void dfs(TreeNode *root, long long sum, int targetSum, int &res) {
        sum += root->val;
        if(sum == targetSum) res++;
        if(root->left) dfs(root->left, sum, targetSum, res);
        if(root->right) dfs(root->right, sum, targetSum, res);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int res = 0;
        while(Q.size()) {
            int size = Q.size();
            while(size--) {
                TreeNode *curr = Q.front();
                Q.pop();
                dfs(curr, 0, targetSum, res);
                if(curr->left) Q.push(curr->left);
                if(curr->right) Q.push(curr->right);
            }
        }
        return res;
    }
};