/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> links;
    void dfs(TreeNode* root) {
        if(root->left) {
            links[root->left] = root;
            dfs(root->left);
        }
        if(root->right) {
            links[root->right] = root;
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        links[root] = nullptr;
        dfs(root);
        queue<TreeNode*> Q({target});
        map<TreeNode*, bool> visited;
        visited[target] = true;
        vector<int> res;
        while(Q.size() && k >= 0) {
            int size = Q.size();
            while(size--) {
                TreeNode *curr = Q.front();
                Q.pop();
                if(k == 0) res.push_back(curr->val);
                if(curr->left && !visited[curr->left]) {
                    Q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]) {
                    Q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(links[curr] && !visited[links[curr]]) {
                    Q.push(links[curr]);
                    visited[links[curr]] = true;
                }
            }
            k--;
        }
        return res;
    }
};