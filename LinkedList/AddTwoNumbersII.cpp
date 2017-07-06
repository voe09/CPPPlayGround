/*
You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Overflow Problem. Wrong answer below
// So could not transfer linked list to number
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_num = 0, l2_num = 0;
        while (l1) {
            l1_num = l1_num * 10 + l1->val;
            l1 = l1->next;
        }

        while (l2) {
            l2_num = l2_num * 10 + l2->val;
            l2 = l2->next;
        }

        int sum = l1_num + l2_num;
        ListNode *tail = new ListNode(sum % 10);
        sum /= 10;
        while (sum) {
            ListNode *tmp = new ListNode(sum % 10);
            sum /= 10;
            tmp->next = tail;
            tail = tmp;
        }

        return tail;
    }
};

// http://www.cnblogs.com/grandyang/p/6216480.html

