/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

Have you met this question in a real interview? Yes
Example
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
 */

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: head is the head of the linked list
     * @return: head of the linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
        // write your code here
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        while (prev->next) {
            ListNode *curr = prev->next;
            while (curr->next && curr->next->val == curr->val) 
                curr = curr->next;
            if (curr != prev->next) prev->next = curr->next;
            else prev = prev->next;
        }
        return dummy->next;
    }
};
