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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr) {
            ListNode *fwd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *ptr = head;
        ListNode *fast = head;
        while(fast && fast->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // Reverse next half
        slow = reverseList(slow);
        int ans = 0;
        while(slow != NULL) {
            ans = max(ans, slow->val+ptr->val);
            slow = slow -> next;
            ptr = ptr -> next;
        }
        return ans;
    }
};