/*
Given a linked list and a value x, partition it such that all nodes less than 
x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the 
two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = head;
        ListNode* slow = dummy;
        while (fast && fast->val < x) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* larger = fast;

        ListNode *prev = slow;
        while (fast) {
            if (fast->val >= x) {
                prev = prev->next;
                fast = fast->next;
            }
            else {
                ListNode *curr = fast;
                fast = fast->next;
                slow->next = curr;
                curr->next = larger;
                slow = slow->next;
                prev->next = fast;
            }
        }
        return dummy->next;
    }
};
