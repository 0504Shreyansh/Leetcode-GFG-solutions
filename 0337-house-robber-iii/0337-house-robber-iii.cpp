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
    /*Concept -> Maximum alternating sum in a tree
    1. Create a pair.
    2. first stores the sum of alternating levels.
    3. second stores the maximum sum of the preceeding level not including the root->val.
    */
    pair<int,int> getSum(TreeNode* root) {
        if(!root) 
            return {0,0};
        
        pair<int,int> l = getSum(root->left);
        pair<int,int> r = getSum(root->right);
        pair<int,int> ans;
        
        // Kind of swap at ans.first
        ans.first = root->val + l.second + r.second;
        // At ans.second, store the maximum of both left and right
        ans.second = max(l.first,l.second) + max(r.first,r.second);
        
        return ans;
    }
    int rob(TreeNode* root) {
        pair<int,int> ans = getSum(root);
        int res = max(ans.first,ans.second);
        return res;
    }
};