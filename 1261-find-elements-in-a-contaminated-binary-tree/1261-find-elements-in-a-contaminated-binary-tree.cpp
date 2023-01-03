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
class FindElements {
public:
    vector<int> ele;
    FindElements(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        while(q.size()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                TreeNode* p = q.front(); q.pop();
                int data = p->val;
                ele.push_back(data);
                if(p->left) {
                    p->left->val = 2*data+1;
                    q.push(p->left);
                }
                if(p->right) {
                    p->right->val = 2*data+2;
                    q.push(p->right);
                }
            }
        }
    }
    
    bool find(int target) {
        for(auto i : ele) {
            if(i == target)
                return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */