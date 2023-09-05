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
    map<TreeNode*, bool> visit;
    string ans;
    void build(TreeNode* root, int startValue, TreeNode* &start) {
        if (!root) return ;
        if (root->left)
            par[root->left] = root;
        if (root->right)
            par[root->right] = root;
        build(root->left, startValue, start);
        build(root->right, startValue, start);
        if (root->val == startValue)
            start = root;
    }
    bool dfs(TreeNode* root, int end, string& cur) {
        if (root == NULL || visit[root]) return false;
        if (end == root->val) {
            ans = cur;
            return true;
        }
        visit[root] = 1;
        cur += "U";
        bool P = dfs(par[root], end, cur);
        cur.pop_back();
        cur += "L";
        bool L = dfs(root->left, end, cur);
        cur.pop_back();
        cur += "R";
        bool R = dfs(root->right, end, cur);
        cur.pop_back();
        return (P || L || R);
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* start;
        par[root] = NULL;
        build(root, startValue, start);
        string cur;
        dfs(start, destValue, cur);
        return ans;
    }
};