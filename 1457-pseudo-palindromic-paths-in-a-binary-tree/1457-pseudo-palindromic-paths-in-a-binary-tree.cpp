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
    void getPaths(TreeNode* root, vector<int> dig, int &paths) {
        if(!root) 
            return;
        
        dig[root->val]++;
        if(!root->left && !root->right) {
            int oddCount = 0;
            for(auto i:dig) {
                if(i&1) oddCount++;
            }
            if(oddCount <= 1) paths++;
        }
        
        getPaths(root->left,dig,paths);
        getPaths(root->right,dig,paths);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int paths = 0;
        vector<int> dig(10);
        getPaths(root,dig,paths);
        
        return paths;
    }
};