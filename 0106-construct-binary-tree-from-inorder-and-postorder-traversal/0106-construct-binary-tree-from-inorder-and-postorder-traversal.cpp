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
    TreeNode* create(vector<int> inorder, vector<int> postorder, int inS, int inE, int postS, int postE, unordered_map<int,int> &mp) {
        if (inS>inE || postS>postE) 
            return NULL;
        TreeNode* root = new TreeNode(postorder[postE]);
        int ind = mp[root->val];
        int n = ind - inS;
        root->left = create(inorder, postorder, inS, ind-1, postS, postS+n-1, mp);
        root->right = create(inorder, postorder, ind+1, inE, postS+n, postE-1, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        return create(inorder, postorder, 0, n-1, 0, n-1, mp);
    }
};