class Solution {
public:
    int solve(unordered_map<int,int> &mp, TreeNode* root) {
        if(!root)
            return 0;
        
        int lvalue = solve(mp,root->left);
        int rvalue = solve(mp,root->right);
        int curr = root->val;
        int data = lvalue + rvalue + curr;
        mp[data]++;
        return data;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        vector<int> ans;
        
        int x = solve(mp,root);
        int maxCount = 0;
        for(auto i:mp) {
            maxCount = max(maxCount,i.second);
            // cout<<i.first<<" "<<i.second<<endl;
        }
        for(auto i:mp) {
            if(i.second==maxCount)
                ans.push_back(i.first);
        }
        return ans;
    }
};
