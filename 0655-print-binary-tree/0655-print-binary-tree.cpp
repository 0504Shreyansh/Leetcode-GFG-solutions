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
    int height(TreeNode* root) {
        return (!root) ? 0 : 1 + max(height(root->left), height(root->right));
    }
    void dfs(TreeNode* root, int x, int y, int H, vector<vector<string>>& answer) {
        if (!root) return ;
        dfs(root->left, x+1, y-pow(2, H-x-2), H, answer);
        answer[x][y] = to_string(root->val);
        dfs(root->right, x+1, y+pow(2, H-x-2), H, answer);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int H = height(root);
        vector<vector<string>> answer(H, vector<string> (pow(2, H) - 1));
        dfs(root, 0, (pow(2, H)-1)/2, H, answer);
        return answer;
    }
};