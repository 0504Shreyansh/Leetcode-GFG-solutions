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
    TreeNode* create(int& i, vector<int>& t, int mini, int maxi, bool& done) {
        if (i == t.size()) done = 1;
        if (i >= t.size() || t[i] < mini || t[i] > maxi) return NULL;
        TreeNode* root = new TreeNode(t[i++]);
        root -> left = create(i, t, mini, root->val, done);
        root -> right = create(i, t, root->val, maxi, done);
        return root;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> t;
        for (int i = 1; i <= n; i++) 
            t.push_back(i);
        vector<vector<int>> p({t});
        while (next_permutation(begin(t),end(t))) {
            p.push_back(t);
        }
        vector<TreeNode*> ans;
        for (auto &it : p) {
            int i = 0;
            bool done = 0;
            TreeNode* cur = create(i, it, INT_MIN, INT_MAX, done);
            if (done) ans.push_back(cur);
        }
        return ans;
    }
};