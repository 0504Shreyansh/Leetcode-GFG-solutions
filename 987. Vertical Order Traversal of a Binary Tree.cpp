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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,vector<int>>> mp;
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(q.size()) {
            auto i = q.front(); q.pop();
            TreeNode* p = i.first;
            int x = i.second.first, y = i.second.second;
            mp[x][y].push_back(p->val);
            if(p->left) q.push({p->left,{x-1,y+1}});
            if(p->right) q.push({p->right,{x+1,y+1}});
        }
        
        for(auto i:mp) {
            vector<int> t;
            for(auto j:i.second) {
                sort(j.second.begin(),j.second.end());
                for(auto k:j.second) {
                    t.push_back(k);
                }
                // sort(t.begin(),t.end());
            }
            
            ans.push_back(t);
        }
        return ans;
    }
};
