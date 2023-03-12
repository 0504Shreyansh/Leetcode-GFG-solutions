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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        if(n==0) 
            return NULL;
        
        priority_queue<pair<int,ListNode*>> pq;
        for(int i = 0; i < n; i++) {
            ListNode *p = lists[i];
            while(p) {
                pq.push({-p->val, p});
                p = p->next;
            }
        }
        
        if(pq.size()==0)
            return NULL;
        ListNode* head = pq.top().second, *tail = pq.top().second;
        pq.pop();
        
        while(pq.size()) {
            tail -> next = pq.top().second;
            tail = pq.top().second;
            pq.pop(); 
        }
        tail -> next = NULL;
        
        return head;
    }
};