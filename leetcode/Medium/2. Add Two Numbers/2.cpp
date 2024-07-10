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
        ListNode* dummy = new ListNode(-1);
        dummy->next = l1;

        int carry = 0, now = 0;
        while(l1!=nullptr || l2!=nullptr || carry > 0){
            now = carry;
            if(l1!=nullptr){
                now += l1->val;
            }

            if(l2!=nullptr){
                now += l2->val;
                l2 = l2->next;
            }

            carry = now / 10;
            now = now % 10;
            if(l1 == nullptr) l1 = new ListNode(now);
            else l1->val = now;
            cout << "L1: " << l1->val << endl;
            l1 = l1->next;
            
            
            cout << "carry: " << carry << endl;
            cout << "now: " << now << endl;
            cout << endl;
        }

        if(now > 0) l1 = new ListNode(now);
        
        return dummy->next;
    }
};

// TC: O(max(l1, l2))
// SC: O(n)

