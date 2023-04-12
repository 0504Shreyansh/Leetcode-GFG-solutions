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
public:
    string ans;
    unordered_map<TreeNode*,TreeNode*> nodeToParent;
    unordered_map<TreeNode*,int> vis;
    TreeNode* start;
    void traverse(TreeNode* root, int &startValue) {
        if(!root)
            return ;
        traverse(root->left, startValue);
        traverse(root->right, startValue);
        if(root->left)
            nodeToParent[root->left] = root;
        if(root->right)
            nodeToParent[root->right] = root;
        if(root->val==startValue)
            start = root;
    }
    
    bool dfs(TreeNode* start, int &endValue, string &cur) {
        if(start==NULL || vis[start]==1)
            return false;
        if(start->val==endValue) {
            ans = cur;
            return true;
        }
        vis[start] = 1;
        cur += "L";
        bool a = dfs(start->left, endValue, cur);
        cur.pop_back();
        cur += "R";
        bool b = dfs(start->right, endValue, cur);
        cur.pop_back();
        cur += "U";
        bool c = dfs(nodeToParent[start], endValue, cur);
        cur.pop_back();
        return a || b || c; 
    }
    
    string getDirections(TreeNode* root, int startValue, int endValue) {
        
        // Create node to parent links 
        nodeToParent[root] = NULL;
        traverse(root, startValue);
        
        // Perform dfs and find out the direction string
        string cur;
        dfs(start, endValue, cur);
        
        return ans;
    }
};