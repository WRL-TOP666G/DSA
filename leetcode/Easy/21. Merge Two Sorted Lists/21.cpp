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

// Recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list2 == nullptr) return list1;
        if(list1 == nullptr) return list2;

        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2); 
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// TC: O(n)
// SC: O(n)


// Iteration
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list2 == nullptr) return list1;
        if(list1 == nullptr) return list2;

        ListNode* dummy = new ListNode(-1);
        dummy->next = list1;
        ListNode* prev = dummy;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val < list2->val){
                list1 = list1->next;
            } else {
                ListNode* next = list2->next;
                prev->next = list2;
                list2->next = list1;
                list2 = next;
            }
            prev = prev->next;
        }
        if(list1==nullptr) prev->next = list2;
        return dummy->next;
    }
};

// TC: O(n)
// SC: O(1)
