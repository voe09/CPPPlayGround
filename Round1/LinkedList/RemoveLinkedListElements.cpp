/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *currentNode = head;
        while (currentNode && currentNode->val == val) {
            currentNode = currentNode->next;
        }
        dummy->next = currentNode;
        if (currentNode) {
            ListNode *prev = currentNode;
            currentNode = currentNode->next;
            while (currentNode) {
                if (currentNode->val != val) {
                    prev = currentNode;
                    currentNode = currentNode->next;
                } else {
                    while (currentNode && currentNode->val == val) {
                        currentNode = currentNode->next;
                    }
                    prev->next = currentNode;
                    prev = prev->next;
                    if (currentNode)
                        currentNode = currentNode->next;
                }
            }
        }
        return dummy->next;
    }
};
