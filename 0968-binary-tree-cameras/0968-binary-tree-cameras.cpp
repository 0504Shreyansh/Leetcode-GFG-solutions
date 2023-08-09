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
private:
    /* 
    -1 --> need camera urgently
    0 --> no urgent need
    1 --> can provide camera facility
    */
    int cameras = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        if (l == -1 || r == -1) {
            cameras++;
            return 1;
        }
        if (l == 0 && r == 0) return -1;
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == -1) cameras++;
        return cameras;
    }
};