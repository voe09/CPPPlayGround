/*
Given a list, rotate the list to the right by k places, 
where k is non-negative.

Have you met this question in a real interview? Yes
Example
Given 1->2->3->4->5 and k = 2, return 4->5->1->2->3.
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
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode * rotateRight(ListNode * head, int k) {
        // write your code here
        if (!head) return head;
        ListNode *curr = head;
        int cnt = 1;
        while (curr->next) {
            curr = curr->next;
            ++cnt;
        }
        curr->next = head;
        k %= cnt;
        curr = head;
        while (cnt > k + 1) {
            curr = curr->next;
            --cnt;
        }

        ListNode *res = curr->next;
        curr->next = nullptr;
        return res;
    }
};
