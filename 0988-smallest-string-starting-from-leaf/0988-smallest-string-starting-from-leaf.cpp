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
    void call(vector<string> &ans, TreeNode* root, string s) {
        if(!root)
            return ;
        s += char(root->val+97);
        if(!root->left && !root->right) {
            reverse(s.begin(),s.end());
            ans.push_back(s);
        }
        call(ans,root->left,s);
        call(ans,root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        string s;
        call(ans,root,s);
        string smallest = *min_element(ans.begin(),ans.end());
        // for(auto i:ans) cout<<i<<" "; cout<<endl;
        return smallest;
    }
};