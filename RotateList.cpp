/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
        if (k <= 0 || head == NULL) return head;
        ListNode* current_node = head;
        int len = 1;
        while (current_node->next != NULL) {
            current_node = current_node->next;
            ++len;
        }
        current_node->next = head;
        k = k % len;
        ListNode* res = head;
        for (int i = 0; i < len - k; ++i) {
            current_node = current_node->next;
            res = res->next;
        }
        current_node->next = NULL;
        return res;
    }
};
