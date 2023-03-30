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
    unordered_map<TreeNode*,TreeNode*> nodeToParent;
    int pairs = 0;
    void create(TreeNode* root) {
        if(root == NULL)
            return ;
        create(root->left);
        if(root->left)
            nodeToParent[root->left] = root;
        if(root->right)
            nodeToParent[root->right] = root;
        create(root->right);
    }
    void findAns(TreeNode* root, int distance) {
        if(root == NULL)
            return ;
        findAns(root->left, distance);
        findAns(root->right, distance);
        if(!root->left && !root->right) {
            
            int dis = distance + 1;
            unordered_map<TreeNode*,int> vis;
            queue<TreeNode*> Q({root});
            vis[root] = vis[NULL] = true;
            
            while(dis--) {
                int N = Q.size();
                while(N--) {
                    TreeNode* cur = Q.front();
                    Q.pop();
                    
                    if(!cur->left && !cur->right && cur != root)
                        pairs++;
                    
                    if(!vis[cur->left]) {
                        vis[cur->left] = 1;
                        Q.push(cur->left);
                    }
                    if(!vis[cur->right]) {
                        vis[cur->right] = 1;
                        Q.push(cur->right);
                    }
                    if(!vis[nodeToParent[cur]]) {
                        vis[nodeToParent[cur]] = 1;
                        Q.push(nodeToParent[cur]);
                    }
                }
            }
        }
    }
    int countPairs(TreeNode* root, int distance) {
        
        // create() -> creates Node -> Parent links
        nodeToParent[root] = NULL;
        create(root);
        
        
        findAns(root, distance);
        
        // Half the count of pairs bcoz (a, b) & (b, a) will be counted twice
        pairs /= 2;
        
        return pairs;
    }
};