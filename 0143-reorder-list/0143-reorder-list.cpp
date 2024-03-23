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
        ListNode* prev = nullptr, *curr = head, *forward;
        while (curr != nullptr) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (!head->next) return ;
        
        // find the mid and separate the 2 lists
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head1 = head, *head2 = slow->next;
        slow->next = nullptr;
        head2 = reverse(head2);
        
        // merge alternatively
        ListNode* curr1 = head1, *curr2 = head2;
        ListNode* next1 = curr1->next, *next2 = curr2->next;
        while (curr2 && next1) {
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = next1;
            next1 = next1->next;
            curr2 = next2;
            if (next2) next2 = next2->next;
        }
        if (curr2) {
            curr1->next = curr2;
        }
        
        head = head1;
    }
};