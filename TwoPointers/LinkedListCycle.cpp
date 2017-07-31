/*
 * Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* Floyd's Cycle-Finding Algorithm
 * Traverse linked list using two pointers.  Move one pointer by one and other 
 * pointer by two.  If these pointers meet at some node then there is a loop.  
 * If pointers do not meet then linked list doesn’t have loop.
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
