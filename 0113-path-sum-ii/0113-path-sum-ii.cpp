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
    void call(TreeNode* root, int targetSum, int sum, vector<int> &v, vector<vector<int>> &ans) {
        if(!root)
            return;
        
        sum += root->val;
        v.push_back(root->val);
     
        if(!root->left && !root->right) {
            if(targetSum==sum) {
                ans.push_back(v);
            }// return;
        }
        call(root->left,targetSum,sum,v,ans);
        call(root->right,targetSum,sum,v,ans);
        // sum -= root->val;
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        int sum = 0;
        call(root,targetSum,sum,v,ans);
        
        return ans;
    }
};