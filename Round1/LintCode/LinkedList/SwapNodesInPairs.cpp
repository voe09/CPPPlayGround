/*
Given a linked list, swap every two adjacent nodes and return its head.

Given 1->2->3->4, you should return the list as 2->1->4->3.

Challenge 
Your algorithm should use only constant space. You may not modify the
values in the list, only nodes itself can be changed.
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
    /*
     * @param head: a ListNode
     * @return: a ListNode
     */
    ListNode * swapPairs(ListNode * head) {
        // write your code here
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode *first = head;
        while (first && first->next) {
            ListNode *second = first->next;
            ListNode *nxt = second->next;
            prev->next = second;
            second->next = first;
            first->next = nxt;
            prev = first;
            first = nxt;
        }
        return dummy->next;
    }
};
