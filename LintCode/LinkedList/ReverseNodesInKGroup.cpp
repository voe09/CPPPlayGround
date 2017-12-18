/*
Given a linked list, reverse the nodes of a linked list k at a time and return
its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end
should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

Have you met this question in a real interview? Yes
Example
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
    /*
     * @param head: a ListNode
     * @param k: An integer
     * @return: a ListNode
     */
    ListNode* reverseGroup(stack<ListNode*> &stk, ListNode *prev, ListNode *last) {
        ListNode *curr = prev;
        while (!stk.empty()) {
            curr->next = stk.top();
            stk.pop();
            curr = curr->next;
        }
        curr->next = last;
        return curr;
    }

    ListNode * reverseKGroup(ListNode * head, int k) {
        // write your code here
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode *curr = head;
        stack<ListNode*> stk;
        while (curr) {
            while (curr && stk.size() < k) {
                stk.push(curr);
                curr = curr->next;
            }

            if (stk.size() == k) {
                prev = reverseGroup(stk, prev, curr);
            }
        }
        return dummy->next;
    }
};
