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
    ListNode* node;
    int N;
    Solution(ListNode* head) {
        node = head;
        N = 0;
        while (head) {
            N++;
            head = head -> next;
        }
    }
    
    int getRandom() {
        int count = rand() % N;
        ListNode* ans = node;
        while (ans && count--) {
            ans = ans -> next;
        }
        return ans -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */