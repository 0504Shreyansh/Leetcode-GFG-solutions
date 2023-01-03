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
    int cnt = 0;
    pair<int,int> getCount(TreeNode* root) {
        if(!root) 
            return {0,0};
        pair<int,int> l = getCount(root->left);
        pair<int,int> r = getCount(root->right);
        pair<int,int> ans;
        ans.second = root->val + l.second + r.second;
        ans.first = 1 + l.first + r.first;
        if(ans.second/ans.first == root->val){
            // cout<<ans.first<<' '<<ans.second<<' '<<root->val<<endl;    
            cnt++;
        }
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> ans = getCount(root);
        // cout << endl;
        return cnt;
    }
};