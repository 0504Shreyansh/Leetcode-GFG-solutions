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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2, ansStack;
        while(l1) {s1.push(l1->val); l1 = l1 -> next;}
        while(l2) {s2.push(l2->val); l2 = l2 -> next;}
        int carry = 0;
        while(s1.size() || s2.size() || carry) {
            int val = carry;
            if(s1.size()) { val += s1.top(); s1.pop(); }
            if(s2.size()) { val += s2.top(); s2.pop(); }
            carry = val / 10;
            val %= 10;
            ansStack.push(val);
        }
        // without reversing use stack :)
        ListNode *res = new ListNode(-1);
        ListNode *ans = res;
        while(ansStack.size()) {
            res -> next = new ListNode(ansStack.top()); 
            ansStack.pop(); 
            res = res -> next;
        }
        return ans->next;
    }
};