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
        // cout<<l.first<<' '<<l.second<<"  "<<r.first<<' '<<r.second<<endl;
        ans.first = root->val + l.second + r.second;
        ans.second = max(l.first,l.second) + max(r.first,r.second);
        // cout<<ans.first<<' '<<ans.second<<endl;
        return ans;
    }
    int rob(TreeNode* root) {
        pair<int,int> ans = getSum(root);
        // cout<<ans.first<<' '<<ans.second<<endl<<endl;
        return max(ans.first,ans.second);
    }
};