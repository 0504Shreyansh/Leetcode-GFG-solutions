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
class BSTIterator {
public:
    vector<int> nodes;
    int index = 0;
    void morrisTraversal(TreeNode* root) {
        if(!root) return ;
        TreeNode* curr = root, *pre;
        while(curr) {
            if(!curr->left) {
                nodes.push_back(curr->val);
                curr = curr->right;
            }   
            else {
                pre = curr->left;
                while(pre->right && pre->right!=curr)
                    pre = pre->right;
                if(!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                }
                else {
                    pre->right = NULL;
                    nodes.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
    BSTIterator(TreeNode* root) {
        morrisTraversal(root);
        // for(auto i : nodes) cout<<i<<' '; cout<<endl;
    }
    
    int next() {
        if(index < nodes.size())
            return nodes[index++];
        return -1;
    }
    
    bool hasNext() {
        return (index < nodes.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */