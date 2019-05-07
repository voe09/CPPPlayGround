/*
Reverse a linked list.

Have you met this question in a real interview? Yes
Example
For linked list 1->2->3, the reversed linked list is 3->2->1

Challenge 
Reverse it in-place and in one-pass
 */

/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        // write your code here
        if (!head) return nullptr;
        ListNode *dummy = nullptr;
        ListNode *curr = dummy;
        ListNode *next = head;
        while (next) {
            ListNode* tmp = next;
            next = next->next;
            tmp->next = curr;
            curr = tmp;
        }
        return curr;
    }
};
