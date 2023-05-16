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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next)
            return head;
            
        ListNode *temp = new ListNode(-1);
        ListNode *prev = temp;
        ListNode *curr = head;
        while(curr && curr->next) {
            prev -> next = curr -> next;  //similar to swapping
            curr -> next = prev -> next -> next;
            prev -> next -> next = curr;
            
            prev = curr;     //further traversal
            curr = curr -> next;
        }
        return temp -> next;
    }
};