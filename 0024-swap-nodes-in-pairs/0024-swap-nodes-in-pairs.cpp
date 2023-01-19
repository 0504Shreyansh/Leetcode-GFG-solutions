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
    ListNode* recursiveSwapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* n = head->next;
        head->next = recursiveSwapPairs(n->next);
        n->next = head;
        return n;
    }
    ListNode* swapPairs(ListNode* head) {
        
        return recursiveSwapPairs(head);
        
//         if(!head || !(head->next)) 
//             return head;
        
//         ListNode *curr = head, *prev = NULL;
//         ListNode* ans = head->next;
        
//         while(curr) {
//             ListNode* temp = curr->next;
//             curr->next = temp->next;
//             temp->next = curr;
//             if(prev)
//                 prev->next = temp;
//             prev = curr;
//             curr = curr->next;
//         }
        
//         return ans;
    }
};