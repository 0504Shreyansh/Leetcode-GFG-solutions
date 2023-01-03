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
/*Concept -> For an even valued node p, check for p->left->left, p ->left->right, p->right->left, p->right->right. And push accordingly to avoid runtime error.
*/
public:
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        
        while(q.size()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                TreeNode* p = q.front(); q.pop();
                if(!(p->val&1)) {
                    if(p->left){
                        if(p->left->left)
                        sum+=p->left->left->val; 
                        if(p->left->right) 
                        sum+=p->left->right->val;
                    }
                    if(p->right){
                        if(p->right->left)
                        sum+=p->right->left->val;
                        if(p->right->right) 
                        sum+=p->right->right->val;
                    }
                }
                if(p->left) {
                    if(p->left->left || p->left->right)
                        q.push(p->left);
                }
                if(p->right) {
                    if(p->right->left || p->right->right)
                        q.push(p->right);
                }
            }
        }
    
        return sum;    
    }
};