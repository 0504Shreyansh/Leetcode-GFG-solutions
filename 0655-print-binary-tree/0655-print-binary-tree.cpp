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
    int findHeight(TreeNode* root) {
        if(!root) 
            return 0;
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        
        int height = findHeight(root), x = 0;
        int n = height, m = pow(2, height) - 1;
        
        vector<vector<string>> ans(n, vector<string> (m));
        ans[x][(m-1)/2] = to_string(root->val);
        queue<pair<TreeNode*,int>> q({{root, (m-1)/2}});        
        
        while(q.size()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) 
            {
                auto cur = q.front();
                q.pop();
                TreeNode* curNode = cur.first;
                int y = cur.second;
        
                if(curNode->left) 
                {
                    int curr_y = y - (1<<(height-x-2));
                    ans[x+1][curr_y] = to_string(curNode->left->val);
                    q.push({curNode->left, curr_y});
                }
                if(curNode->right) 
                {
                    int curr_y = y + (1<<(height-x-2));
                    ans[x+1][curr_y] = to_string(curNode->right->val);
                    q.push({curNode->right, curr_y});
                }
            }
            x++;
        }
    
        return ans;
    }
};