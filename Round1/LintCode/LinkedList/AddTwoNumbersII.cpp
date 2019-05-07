/*
You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in forward order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

Have you met this question in a real interview? Yes
Example
Given 6->1->7 + 2->9->5. That is, 617 + 295.

Return 9->1->2. That is, 912.
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
     * @param l1: The first list.
     * @param l2: The second list.
     * @return: the sum list of l1 and l2.
     */
    ListNode * addLists2(ListNode * l1, ListNode * l2) {
        // write your code here
        ListNode* reverse_l1 = reverseList(l1);
        ListNode* reverse_l2 = reverseList(l2);
        ListNode* tmp = addList(reverse_l1, reverse_l2);
        return reverseList(tmp);
    }

private:
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        
        while (curr->next) {
            ListNode* tmp = curr;
            curr = curr->next;
            tmp->next = prev;
            prev = tmp;
        }
        
        curr->next = prev;

        return curr;
    }

    ListNode* addList(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (l1 && l2) {
            int val = l1->val + l2->val + carry;
            carry = val / 10;
            curr->next = new ListNode(val % 10);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 || l2) {
            int val = ((l1 != nullptr) ? l1->val : l2->val) + carry;
            carry = val / 10;
            curr->next = new ListNode(val % 10);
            curr = curr->next;
            if (l1)
                l1 = l1->next;
            else
                l2 = l2->next;
        }

        if (carry > 0) curr->next = new ListNode(carry);
        return dummy->next;
    }
};
