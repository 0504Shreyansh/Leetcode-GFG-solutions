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
    int findLength(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr -> next;
        }
        return len;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);
        int len = findLength(head);  
        int rem = len % k;  
        int i = 0;
        ListNode* curr = head;  
        while (curr) {                     
            ListNode* end = curr;          
            int reqLen = (len / k) - 1;
            if (rem != 0) rem--, reqLen++; 
            while (reqLen-- && end) 
                end = end -> next;
            if (end) {
                ListNode* next = end -> next;
                end -> next = NULL;
                ans[i++] = curr;
                curr = next;
            }
        }
        return ans;
    }
};