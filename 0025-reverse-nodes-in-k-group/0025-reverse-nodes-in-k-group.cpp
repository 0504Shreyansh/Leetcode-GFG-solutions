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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case
        ListNode *tmp = head;
        int cnt = 0;
        while(tmp != NULL) {
            tmp = tmp -> next;
            cnt++;
        }
        // there is no need to reverse the last group bcoz of smaller size than k
        if(cnt < k)  return head;
        // or else go on and further reverse the groups
        
        // further reversals
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        int count = 0;
        // Code for reverse
        while(count++ < k) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        // Reverse the remaining groups
        if(forward != NULL) {
            head -> next = reverseKGroup(forward, k);
        }
        return prev;
    }
};