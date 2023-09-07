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
private:
    ListNode* reverse(ListNode* head) {
        if (!head) return NULL;
        ListNode* curr = head, *prev = NULL, *forward;
        while (curr) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        head = dummy;
        ListNode *h1 = head, *end1, *h2 = NULL, *end2, *h3;
        ListNode *prev = NULL, *curr = head;
        while (curr) {
            left--, right--;
            if (left == 0) {
                end1 = curr;
                h2 = curr -> next;
            
            }
            if (right == -1) {
                end2 = curr;
                h3 = curr -> next;
            }
            curr = curr -> next;
        }
        if (end1) end1 -> next = NULL;
        if (end2) end2 -> next = NULL;
        h2 = reverse(h2);
        end1 -> next = h2;
        curr = h2;
        while (curr && curr -> next) curr = curr -> next;
        if (curr) curr -> next = h3;
        return dummy -> next;
    }
};