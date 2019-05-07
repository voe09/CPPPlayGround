/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode *currentNode = &dummy;
        while (l1 || l2) {
            int sum = (l1? l1->val : 0) + (l2? l2->val : 0) + carry;
            currentNode->next = new ListNode(sum % 10);
            carry =  sum / 10;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            currentNode = currentNode->next;
        }
        if (carry != 0) currentNode->next = new ListNode(carry);
        return dummy.next;
    }
};
