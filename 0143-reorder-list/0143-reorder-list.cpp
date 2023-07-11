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
    ListNode *reverse(ListNode *head) {
        ListNode *cur = head, *prev, *forward;
        while(cur != nullptr) {
            forward = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head -> next == nullptr) return ;
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        cout << slow -> val << endl;
        ListNode *nextHead = slow -> next;
        slow -> next = nullptr;
        ListNode *cur2 = reverse(nextHead);
        ListNode *next2 = cur2 -> next;
        
        ListNode *cur1 = head;
        head = cur1;
        ListNode *next1 = cur1 -> next;
        while(cur1 != nullptr && cur2 != nullptr) {
            cur1 -> next = cur2;
            cur2 -> next = next1;
            cur1 = next1;
            cur2 = next2;
            if(next1) next1 = next1 -> next;
            if(next2) next2 = next2 -> next;
        }
        // cout << nextHead -> val << endl;
    }
};