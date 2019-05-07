/*
Sort a linked list using insertion sort.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr) {
            ListNode* insert = dummy->next;
            ListNode* insert_prev = dummy;
            while (insert != curr && insert->val < curr->val) {
                insert = insert->next;
                insert_prev = insert_prev->next;
            }
            if (insert != curr) {
                ListNode* tmp = curr->next;
                insert_prev->next = curr;
                curr->next = insert;
                prev->next = tmp;
                curr = tmp;
            } else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};


