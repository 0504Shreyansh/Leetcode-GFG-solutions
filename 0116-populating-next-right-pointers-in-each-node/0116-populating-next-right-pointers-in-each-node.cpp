/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        Node *head = root;
        if(!head) return head;
        queue<Node*> q({root});
        // q.push(NULL);
        
        while(q.size()) {
            int n = q.size();
            q.push(NULL);
            while(n--) {
                Node *cur = q.front();
                q.pop();
                // Make next link to the neighbour
                cur->next = q.front();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            q.pop();
        }
        
        return head;
    }
};