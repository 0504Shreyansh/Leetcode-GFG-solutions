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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        // Add row to the above the root
        if(depth==1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }
        
        // Reach the level above the required level
        depth--;
        queue<TreeNode*> q({root});
        while(--depth) {
            int n = q.size();
            while(n--) {
                TreeNode *cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }  
        }
        
        // Change the links to account the new nodes
        while(q.size()) {
            TreeNode *cur = q.front();
            q.pop();
            TreeNode *temp1 = new TreeNode(val);
            TreeNode *temp2 = new TreeNode(val);
            temp1 -> left = cur -> left;
            temp2 -> right = cur -> right;
            cur -> left = temp1;
            cur -> right = temp2;
        }
        
        return root;
    }
};