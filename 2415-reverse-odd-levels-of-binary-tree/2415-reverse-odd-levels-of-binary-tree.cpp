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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> Q({root});
        bool reverse = true;
        
        while (Q.size() != 0)
        {
            int size = Q.size();
            vector<TreeNode*> nodes;
            while (size--) 
            {
                TreeNode *curNode = Q.front();
                Q.pop();
                if(curNode -> left) {
                    Q.push(curNode->left);
                    nodes.push_back(curNode->left);
                }
                if(curNode -> right) {
                    Q.push(curNode->right);
                    nodes.push_back(curNode->right);
                }
            }
            
            // Just reverse the odd levels at the end
            // Caution : Don't try to change the values while in the loop
            // That will only change half of the level due to current change
            // And would not accomodate the next half of the changes.
            if(reverse) {
                vector<int> values;
                for(int i = nodes.size()-1; i >= 0; i--)
                    values.push_back(nodes[i]->val);
                for(int i = 0; i < nodes.size(); i++) 
                    nodes[i] -> val = values[i];
            }  
            
            reverse = !reverse;
        }
        
        return root;
    }
};