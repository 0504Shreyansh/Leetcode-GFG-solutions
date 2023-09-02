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
    map<TreeNode*, TreeNode*> par;
    int height(TreeNode* root) {
        return (!root) ? 0 : 1 + max(height(root->left), height(root->right));
    }
    void dfs(TreeNode* root, int level, vector<TreeNode*>& leafs) {
        if (!root) return ;
        if (level == 1) leafs.push_back(root);
        if (root -> left) par[root -> left] = root;
        if (root -> right) par[root -> right] = root;
        dfs(root->left, level-1, leafs);
        dfs(root->right, level-1, leafs);
    }
    TreeNode* lca(vector<TreeNode*>& leafs) {
        int n = leafs.size();
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> visit;
        for (auto &leaf : leafs) {
            if (++visit[leaf] == n) return leaf;
            q.push(leaf);
        }
        while (q.size()) {
            int size = q.size();
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                if (par[cur]) {
                    if (++visit[par[cur]] == n) return par[cur];
                    q.push(par[cur]);
                }
            }
        }
        return nullptr;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int level = height(root);
        vector<TreeNode*> leafs;
        par[root] = nullptr;
        dfs(root, level, leafs);
        return lca(leafs);
    }
};