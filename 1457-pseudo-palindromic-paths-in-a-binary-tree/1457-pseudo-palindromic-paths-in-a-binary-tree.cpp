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
    int ans;
    void dfs(TreeNode* root, vector<int>& f) {
        if (!root) return ;
        f[root->val]++;
        if (!root->left && !root->right) {
            int oddCount = 0;
            for (int &i : f) oddCount += (i & 1);
            ans += (oddCount <= 1);
        }
        dfs(root->left, f);
        dfs(root->right, f);
        f[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        vector<int> f(10);
        dfs(root, f);
        return ans;
    }
};