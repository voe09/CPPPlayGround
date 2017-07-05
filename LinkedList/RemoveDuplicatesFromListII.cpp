/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(0);

        ListNode *currentNode = dummy;
        ListNode *first = head;
        ListNode *second = head->next;
        while (second) {
            if (first->val != second->val) {
                currentNode->next = first;
                currentNode = currentNode->next;
                first = second;
                second = second->next;
            } else {
                while (second && first->val == second->val) {
                    second = second->next;
                    if (!second) {
                        currentNode->next = NULL;
                        return dummy->next;
                    }
                    if (first->val != second->val) {
                        first = second;
                        second = second->next;
                        if (!second) {
                            currentNode->next = first;
                            return dummy->next;
                        }
                    }
                }
            }
        }
        return dummy->next;
    }
};
