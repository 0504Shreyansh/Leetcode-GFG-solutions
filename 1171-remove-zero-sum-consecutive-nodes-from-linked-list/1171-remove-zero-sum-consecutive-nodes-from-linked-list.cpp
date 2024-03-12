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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* prev, *curr;
        ListNode* tmp = new ListNode(-1);
        tmp->next = head;
        head = tmp;
        for (prev = head; prev != nullptr; prev = prev->next) {
            int sum = 0;
            for (curr = prev->next; curr != nullptr; curr = curr->next) {
                sum += curr->val;
                if (sum == 0) {
                    prev->next = curr->next;
                }
            }
        }
        return head->next;
    }
};