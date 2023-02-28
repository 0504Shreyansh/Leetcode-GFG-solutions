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
    string solve(vector<TreeNode*> &ans, TreeNode* root, unordered_map<string,int> &mp) {
        if(!root)
            return "#";
        string l = solve(ans, root->left, mp);
        string r = solve(ans, root->right, mp);
        string s = l + ',' + r + ',' + to_string(root->val);
        if(mp[s]==1)
            ans.push_back(root), mp[s]=INT_MIN;
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> ans;
        unordered_map<string, int> mp;
        string s = solve(ans, root, mp);
        return ans;
        
    }
};