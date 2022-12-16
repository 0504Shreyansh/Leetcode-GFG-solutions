class Solution {
public:
    void levelOrder(vector<vector<int>> &ans, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(q.size()) {
            TreeNode* p = q.front();
            q.pop();
            if(p==NULL) {
                ans.push_back(v);
                v.clear();
                if(q.size())
                    q.push(NULL);
            }
            else {
                if(p->left) q.push(p->left);  
                if(p->right) q.push(p->right);
                v.push_back(p->val);
            }
        }
        
    }
    bool isEvenOddTree(TreeNode* root) {
        //Obtain level order traversal for the tree
        vector<vector<int>> ans;
        levelOrder(ans,root);
        
        // for(auto i:ans) {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        if(root->val%2==0) return false;
        for(int i=1;i<ans.size();i++) {
            if(i&1) {
                //Check for a single value
                if(ans[i].size()==1 && ans[i][0]&1) 
                    return false;
                for(int j=1;j<ans[i].size();j++) {
                    if(ans[i][j-1]<=ans[i][j] || ans[i][j]&1 || ans[i][j-1]&1) {
                        // cout<<ans[i][j-1]<<" "<<ans[i][j]<<endl;
                        return false;
                    }
                }
            }
            else {
                //Check for a single value
                if(ans[i].size()==1 && ans[i][0]%2==0)
                    return false;
                for(int j=1;j<ans[i].size();j++) {
                    if(ans[i][j-1]>=ans[i][j] || ans[i][j]%2==0 || ans[i][j-1]%2==0) {
                        // cout<<ans[i][j-1]<<" "<<ans[i][j]<<endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
