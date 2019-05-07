/*
Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 * 1. Find the median node
 * 2. reverse the nodes after median
 * 3. solve the problem
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *first = head;
        ListNode *second = head;
        int cnt = 1;
        while (second->next) {
            second = second->next;
            ++cnt;
        }
        ++cnt;
        cnt /= 2;
        
        ListNode *intermedian = head;
        while (cnt > 1) {
            intermedian = intermedian->next;
            --cnt;
        }

        // Reverse the link btw intermedian and second
        ListNode *second_start = intermedian->next;
        ListNode *prev = NULL;
        while (intermedian != NULL) {
            ListNode *tmp = intermedian->next;
            intermedian->next = prev;
            prev = intermedian;
            intermedian = tmp;
        }
        if (second_start)
            second_start->next = NULL;

        // Start the process
        ListNode *curr = new ListNode(0);
        while (first && second) {
            curr->next = first;
            curr = curr->next;
            first = first->next;
            curr->next = second;
            curr = curr->next;
            second = second->next;
        }

        if (first) {
            curr->next = first;
        }
    }
};
