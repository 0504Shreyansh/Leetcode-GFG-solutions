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
    vector<TreeNode*> res;
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> ans;
        // All nodes have been taken.
        if(start > end) {
            ans.push_back(NULL);
            return ans;
        }
        for(int i = start; i <= end; i++) {
            // Recursively create all the possible left and right sub-trees.
            vector<TreeNode*> leftSubTree = solve(start, i-1);
            vector<TreeNode*> rightSubTree = solve(i+1, end);
            for(auto l: leftSubTree) {
                for(auto r: rightSubTree) {
                    TreeNode *cur = new TreeNode(i);
                    cur -> left = l;
                    cur -> right = r;
                    // Push the new tree 
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        // Solve starting from node 1 to n.
        return solve(1, n);
    }
};