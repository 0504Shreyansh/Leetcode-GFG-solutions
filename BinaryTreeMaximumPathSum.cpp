class Solution {
public:
    int maxAns = INT_MIN;
    int f(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int l = max(0, f(root->left));
        int r = max(0, f(root->right));
        int curr = root->val;
        
        maxAns = max(maxAns, l+r+curr);
        return max(l, r)+curr;
        
    }
    int maxPathSum(TreeNode* root) {
        
        int x = f(root);
        return maxAns;
        
    }
};
