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
/*Concept -> 
1. Store nodes with their indices
2. At a particular level, calculate the 
*/
public:
    int widthOfBinaryTree(TreeNode* root) {
        long ans = 0;
        if(!root)
            return ans;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        
        while(q.size()) {
            int n = q.size();
            long l = q.front().first;
            long h = q.back().first;
            ans = max(ans, h-l+1);
            for(int i=0;i<n;i++) {
                long ind = q.front().first;
                TreeNode* p = q.front().second;
                q.pop();
                // cout<<ind<<' '<<l<<' '<<h<<' '<<p->val<<endl;
                if(p->left)
                    q.push({2*ind+1,p->left});
                if(p->right)
                    q.push({2*ind+2,p->right});
            }
        }
        // cout << endl;
        return ans;
    }
};