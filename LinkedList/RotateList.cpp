/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int length = 1;
        ListNode *currentNode = head;
        while (currentNode->next) {
            currentNode = currentNode->next;
            ++length;
        }
        currentNode->next = head;
        
        k = k % length;
        int cnt = 1;
        while (cnt < length - k) {
            head = head->next;
            ++cnt;
        }

        ListNode *res = head->next;
        head->next = NULL;
        return res;
    }
};
