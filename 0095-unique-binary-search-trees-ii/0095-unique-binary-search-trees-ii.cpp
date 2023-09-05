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
    vector<TreeNode*> solve(int low, int high) {
        if (low > high) return {NULL};
        if (low == high) return {new TreeNode(low)};
        vector<TreeNode*> res;
        for (int i = low; i <= high; i++) {
            vector<TreeNode*> L = solve(low, i - 1);
            vector<TreeNode*> R = solve(i + 1, high);
            for (auto &l : L) {
                for (auto &r : R) {
                    res.push_back(new TreeNode(i, l, r));
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};