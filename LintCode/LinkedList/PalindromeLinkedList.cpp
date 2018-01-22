/*
Implement a function to check if a linked list is a palindrome.

Have you met this question in a real interview? Yes
Example
Given 1->2->1, return true

Challenge 
Could you do it in O(n) time and O(1) space?
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
     * @param head: A ListNode.
     * @return: A boolean.
     */
    bool isPalindrome(ListNode * head) {
        // write your code here
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *tail = reverseList(slow);

        while (head && tail && head != tail) {
            if (head->val != tail->val) return false;
            head = head->next, tail = tail->next;
        }
        return true;
    }

private:
    ListNode* reverseList(ListNode *node) {
        ListNode *dummy = nullptr;
        ListNode *prev = dummy, *curr = node;
        while (curr && curr->next) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        if (curr)
            curr->next = prev;
        return curr;
    }
};
