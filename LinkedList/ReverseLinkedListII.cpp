/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !(head->next)) return head;
        if (m == n) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;
        ListNode *first = head, *second = head->next;

        int cnt = 1;
        while (cnt < m) {
            current->next = first;
            current = current->next;
            first = first->next;
            second = second->next;
            ++cnt;
        }
        
        ListNode *tmp = first;
        ListNode *third = second->next;
        // reverse list
        while (cnt < n) {
            second->next = first;
            first = second;
            second = third;
            if (third)
                third = third->next;
            ++cnt;
        }
        
        current->next = first;
        tmp->next = second;
        return dummy->next;
    }
};
