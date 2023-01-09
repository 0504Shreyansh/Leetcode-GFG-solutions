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
    TreeNode* createMapping(TreeNode* root, map<TreeNode*,TreeNode*> &mp, int start) {
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;
        TreeNode* targetNode = NULL;
        while(q.size()) {
            TreeNode *p = q.front(); q.pop();
            if(p->val == start)
                targetNode = p;
            if(p->left) {
                q.push(p->left);
                mp[p->left] = p;
            }
            if(p->right) {
                q.push(p->right);
                mp[p->right] = p;
            }
        }
        return targetNode;
    }
    int burnTime(TreeNode* targetNode, map<TreeNode*,TreeNode*> &mp) {
        int time = 0;
        queue<TreeNode*> q;
        map<TreeNode*,bool> vis;
        q.push(targetNode);
        vis[targetNode] = true;
        while(q.size()) {
            int n = q.size();
            bool inserted = false;
            for(int i=0;i<n;i++) {
                TreeNode* p = q.front(); q.pop();
                if(p->left && !vis[p->left]) {
                    q.push(p->left);
                    vis[p->left] = true;
                    inserted = true;
                }
                if(p->right && !vis[p->right]) {
                    q.push(p->right);
                    vis[p->right] = true;
                    inserted = true;
                }
                if(mp[p] && !vis[mp[p]]) {
                    q.push(mp[p]);
                    vis[mp[p]] = true;
                    inserted = true;
                }
            }
            if(inserted) 
                time++;
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {    
        map<TreeNode*,TreeNode*> mp;
        //Create node -> parent mapping by level order and return the node
        TreeNode* targetNode = createMapping(root,mp,start); 
        //Calculate burning time
        return burnTime(targetNode,mp);
    }
};