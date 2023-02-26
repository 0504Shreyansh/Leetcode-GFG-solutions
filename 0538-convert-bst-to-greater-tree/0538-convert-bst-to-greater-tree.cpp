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
    vector<int> reverseInorder;
    void revInorder(TreeNode* root, bool flag) {
        if(!root)
            return ;
        revInorder(root->right, flag);
        if(flag)
            root->val = reverseInorder.back(), reverseInorder.pop_back();
        else 
            reverseInorder.push_back(root->val);
        revInorder(root->left, flag);
    }
  
    TreeNode* convertBST(TreeNode* root) {
        
        revInorder(root, 0);
        
        for(int i = 1; i < reverseInorder.size(); i++)
            reverseInorder[i] += reverseInorder[i-1];
        reverse(reverseInorder.begin(), reverseInorder.end());
        
        revInorder(root, 1);

        return root;
    }
};