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
private:
    map<int, map<int, priority_queue<int>>> m;
    void dfs(TreeNode* root, int x, int y) {
        if (root == nullptr) return ;
        dfs(root -> left, x - 1, y + 1);
        dfs(root -> right, x + 1, y + 1);
        m[x][y].push(-root -> val);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto &it : m) {
            vector<int> temp;
            for (auto &j : it.second) {
                priority_queue<int> pq = j.second;
                while (pq.size()) {
                    temp.push_back(-pq.top());
                    pq.pop();
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};