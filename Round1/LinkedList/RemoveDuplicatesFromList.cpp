/*
Given a sorted linked list, delete all duplicates such that each element appear 
only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
        ListNode *currentNode = head;
        ListNode *tmp = head->next;
        while (tmp) {
            if (tmp->val != currentNode->val) {
                currentNode->next = tmp;
                currentNode = currentNode->next;
                tmp = tmp->next;
            } else {
                tmp = tmp->next;
            }
        }
        currentNode->next = NULL;
        return head;
    }
};
