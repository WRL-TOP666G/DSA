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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head;
        ListNode* prev = dummy;
        ListNode* fast = head;

        for(int i=0; i<n; i++) fast = fast->next;
        while(fast!=nullptr){
            cur = cur->next;
            prev = prev->next;
            fast = fast->next;
        }

        prev->next = cur->next;

        return dummy->next;
    }
};


// TC: O(n)
// SC: O(1)

