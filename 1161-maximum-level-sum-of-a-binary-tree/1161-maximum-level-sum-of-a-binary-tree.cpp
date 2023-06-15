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
        int max_sum = -1e9;
        int max_sum_level = 0;
        int curr_level = 1;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int size = Q.size();
            int curr_sum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = Q.front();
                Q.pop();
                curr_sum += curr->val;
                if(curr->left != NULL) Q.push(curr->left);
                if(curr->right != NULL) Q.push(curr->right);
            }
            if(max_sum < curr_sum) {
                max_sum = curr_sum;
                max_sum_level = curr_level;
            }
            curr_level++;
        }
        return max_sum_level;
    }
};