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
    vector<TreeNode*> leafs;
    map<TreeNode*, TreeNode*> par;
    void dfs(TreeNode* root) {
        if (!root) return ;
        dfs(root -> left);
        if (root -> left) par[root->left] = root;
        if (root -> right) par[root -> right] = root;
        if (!root->left && !root->right) 
            leafs.push_back(root);
        dfs(root -> right);
    }
    int count(TreeNode* root, int distance) {
        queue<TreeNode*> q({root});
        unordered_map<TreeNode*, bool> visit;
        visit[root] = 1;
        int cnt = 0;
        ++distance;
        while (q.size() && distance-- > 0) {
            int size = q.size();
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                if (!cur -> left && !cur -> right) cnt++;
                if (par[cur] && !visit[par[cur]]) {
                    visit[par[cur]] = 1;
                    q.push(par[cur]);
                }
                if (cur -> left && !visit[cur -> left]) {
                    visit[cur -> left] = 1;
                    q.push(cur -> left);
                }
                if (cur -> right && !visit[cur -> right]) {
                    visit[cur -> right] = 1;
                    q.push(cur -> right);
                }
            }
        }
        return cnt - 1;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        par[root] = nullptr;
        dfs(root);
        int ans = 0;
        for (auto &cur : leafs) {
            ans += count(cur, distance);
        }
        ans /= 2;
        return ans;
    }
};