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
    vector<int> ans;
    int maxCount = 0;
    void dfs(TreeNode* root, int &cnt, int &node) {
        if (root == NULL) {
            return ;
        }
        dfs(root->left, cnt, node);
        if (node == root -> val) {
            cnt++;
        } else {
            cnt = 1;
            node = root -> val;
        }
        if (cnt > maxCount) {
            maxCount = cnt;
            ans.clear();
            ans.push_back(root->val);
        } else if (cnt == maxCount) {
            ans.push_back(root->val);
        }
        dfs(root->right, cnt, node);
    }
public:
    vector<int> findMode(TreeNode* root) {
        int cnt = 0, node = -1e6;
        dfs(root, cnt, node);
        return ans;
    }
};