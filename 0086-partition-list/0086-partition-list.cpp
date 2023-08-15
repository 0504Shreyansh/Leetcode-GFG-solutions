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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = new ListNode(-1);
        ListNode* ans = temp;
        ListNode* newHead = new ListNode(-1);
        newHead -> next = head;
        head = newHead;
        ListNode* prev = head, *cur = head -> next;
        
        while (cur != NULL) {
            if (cur -> val < x) {
                ListNode* tmp = cur -> next;
                prev -> next = tmp;
                cur -> next = NULL;
                temp -> next = cur;
                temp = temp -> next;
                cur = tmp;
            } else {
                prev = cur;
                cur = cur -> next;
            }
        }
        if (newHead -> next) {
            temp -> next = newHead -> next;
        }
        return ans -> next;
    }
};