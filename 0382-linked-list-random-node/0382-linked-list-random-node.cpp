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
class Solution {
public:
    ListNode* x;
    int n, len = 0;
    Solution(ListNode* head) {
        x = head;
        while(head) {
            len++;
            head = head -> next;
        }
        
    }
    
    int getRandom() {
        ListNode* y = x;
        int z = random() % len;
        while(z--) 
            y = y -> next;           
        
        return y->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */