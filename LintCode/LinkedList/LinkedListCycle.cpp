/*
Given a linked list, determine if it has a cycle in it.
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
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode * head) {
        // write your code here
        if (!head || !head->next) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        do {
            fast = fast->next->next;
            slow = slow->next;
        } while (fast && fast->next && slow != fast);
        
        if (slow == fast) return true;
        return false;
    }
};

