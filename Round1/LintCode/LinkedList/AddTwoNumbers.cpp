/*
You have two numbers represented by a linked list, where each node contains a 
single digit. The digits are stored in reverse order, such that the 1's digit 
is at the head of the list. Write a function that adds the two numbers and 
returns the sum as a linked list.

Have you met this question in a real interview? Yes
Example
Given 7->1->6 + 5->9->2. That is, 617 + 295.

Return 2->1->9. That is 912.

Given 3->1->5 and 5->9->2, return 8->0->8.
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode * addLists(ListNode * l1, ListNode * l2) {
        // write your code here
        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode *cur = nullptr;
        while (l1 && l2) {
            int val = (l1->val + l2->val) + carry;
            carry = val / 10;
            cur = new ListNode(val % 10);
            prev->next = cur;
            prev = cur;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 || l2) {
            int val = ((l1 != nullptr) ? l1->val : l2->val) + carry;
            carry = val / 10;
            cur = new ListNode(val % 10);
            prev->next = cur;
            prev = cur;
            if (l1 != nullptr)
                l1 = l1->next;
            else
                l2 = l2->next;
        }

        if (carry > 0) {
            cur = new ListNode(carry);
            prev->next = cur;
        }
        return dummy->next;
    }
};
