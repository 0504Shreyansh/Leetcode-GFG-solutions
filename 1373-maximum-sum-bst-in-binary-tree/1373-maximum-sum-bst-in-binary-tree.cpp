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
class Node {
public:
    int mini, maxi, sum;
    Node(int _mini, int _maxi, int _sum) {
        mini = _mini;
        maxi = _maxi;
        sum = _sum;
    }  
};

class Solution {
private:
    int ans = 0;
    Node* dfs(TreeNode* root) {
        if (!root) return new Node(INT_MAX, INT_MIN, 0);
        Node* l = dfs(root -> left);
        Node* r = dfs(root -> right);
        if (l->maxi < root->val && root->val < r->mini) {
            ans = max(ans, l->sum + r->sum + root->val);
            return new Node(min({l->mini, r->mini, root->val}), max({l->maxi, r->maxi, root->val}), l->sum + r->sum + root->val);
        } 
        return new Node(INT_MIN, INT_MAX, 0);
    }
public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};