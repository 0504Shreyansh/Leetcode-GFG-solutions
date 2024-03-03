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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head, *prev = NULL;
        while (curr) {
            len++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < len - n; i++) {
            prev = curr;
            curr = curr->next;
        }
        if (prev) prev->next = curr->next;
        else head = head->next;
        curr->next = NULL;
        return head;
    }
};