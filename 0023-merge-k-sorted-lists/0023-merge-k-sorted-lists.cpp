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
    ListNode *merge(ListNode *head1, ListNode *head2) {
        if(!head1 && !head2) return nullptr;
        if(!head1) return head2;
        if(!head2) return head1;
        if(head1 -> val > head2 -> val) swap(head1, head2);
        ListNode *cur1 = head1;
        ListNode *next1 = cur1 -> next;
        ListNode *cur2 = head2;
        ListNode *next2 = cur2 -> next;
        ListNode *newHead = cur1;
        while(next1 != nullptr && cur2 != nullptr) {
            if(cur1 -> val <= cur2 -> val && cur2 -> val <= next1 -> val) {
                cur1 -> next = cur2;
                cur2 -> next = next1;
                cur1 = cur2;
                cur2 = next2;
                if(next2) next2 = next2 -> next;
            } else {
                cur1 = next1;
                next1 = next1 -> next;
            }
        } 
        if(cur2 != nullptr) {
            cur1 -> next = cur2;
        }
        return newHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for(ListNode *it : lists) {
            ans = merge(ans, it);
        }
        return ans;
    }
};