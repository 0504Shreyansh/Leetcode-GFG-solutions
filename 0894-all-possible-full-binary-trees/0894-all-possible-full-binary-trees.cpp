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
    vector<TreeNode*> dfs(int n) {
        if (n % 2 == 0) {
            return {};
        }
        if (n == 1) {
            return {new TreeNode(0)};
        }
        vector<TreeNode*> ans;
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> left = dfs(i);
            vector<TreeNode*> right = dfs(n - i - 1);
            for (auto &l : left) {
                for (auto &r : right) {
                    TreeNode *root = new TreeNode(0, l, r);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return dfs(n);
    }
};