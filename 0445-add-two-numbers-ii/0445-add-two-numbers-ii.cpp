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
    ListNode *reverse(ListNode *head) {
        ListNode *cur = head, *prev = nullptr, *forward;
        while(cur != nullptr) {
            forward = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = forward;
        }
        return prev;
    } 
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        ListNode *temp = new ListNode(-1);
        ListNode *ans = temp;
        while(l1 || l2 || carry) {
            int val = carry;
            if(l1) { val += l1 -> val; l1 = l1 -> next; }
            if(l2) { val += l2 -> val; l2 = l2 -> next; }
            carry = val / 10;
            val %= 10;
            temp -> next = new ListNode(val);
            temp = temp -> next;
        }
        return reverse(ans->next);
    }
};