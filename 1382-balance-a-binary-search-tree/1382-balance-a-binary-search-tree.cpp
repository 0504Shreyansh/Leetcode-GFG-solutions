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
    void inorder(TreeNode* root, vector<int> &in) {
        if(!root) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* createBalancedBST(vector<int> &in, int start, int end) {
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(in[(start+end)/2]);
        root->left = createBalancedBST(in,start,(start+end)/2-1);
        root->right = createBalancedBST(in,(start+end)/2+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        int start = 0, end = in.size()-1;
        return createBalancedBST(in,start,end);
    }
};