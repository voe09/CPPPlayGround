/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if ((!head) || k <= 1) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *first = head;
        ListNode *second = head;
        ListNode *currentNode = dummy;

        int cnt = 1;
        while (cnt < k) {
            if (second) {
                second = second->next;
                ++cnt;
            } else break;
        }
        
        if (cnt != k || !second) return head;

        while (true) {
            ListNode *next_first = second->next;
            // reverse
            ReverseLinkedList(first, second);
            currentNode->next = second;
            currentNode = first;
            // next loop
            if (next_first) {
                first = next_first;
                second = first;
                cnt = 1;
                while (cnt < k) {
                    if (second) {
                        second = second->next;
                        ++cnt;
                    } else break;
                }
            } else {
                currentNode->next = NULL;
                break;
            };

            if (!second) {
                currentNode->next = next_first;
                break;
            };
        }

        return dummy->next;
    }

private:
    void ReverseLinkedList(ListNode *start, ListNode *end) {
        ListNode *first = start;
        ListNode *second = first->next;
        ListNode *next_first = second->next;
        while (first != end) {
            second->next = first;
            first = second;
            second = next_first;
            if (second)
                next_first = second->next;
        }
    }
};
