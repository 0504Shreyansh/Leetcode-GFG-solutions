/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(TreeNode* root, ListNode* head) {
        // If head first becomes NULL -> all the LL is present
        if (head == NULL) return true;
        // Tree has ended (not found 404)
        if (root == NULL) return false;
        // Not present
        if (root->val != head->val) return false;
        // Check in both the directions whether LL is present or not
        return (check(root->left, head->next) || check(root->right, head->next));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        queue<TreeNode*> Q({root});
        while (Q.size()) {
            int size = Q.size();
            while (size--) {
                TreeNode* cur = Q.front();
                Q.pop();
                if (check(cur, head))
                    return true;
                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }
        }
        
        return false;
    }
};