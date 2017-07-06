/*
 Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode *prev = head, *current = head->next, *next = head->next->next;
        while (current) {
            current->next = prev;
            prev = current;
            current = next;
            if (next)
                next = next->next;
        }
        head->next = NULL;
        return prev;
    }
};


